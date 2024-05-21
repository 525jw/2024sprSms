#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long long_t;
typedef struct _node* node_ptr;

struct _node {
    long_t num;
    node_ptr next;
};

node_ptr collatz(long_t n);
void clean(node_ptr head);

int main()
{
    int n; scanf("%d\n", &n);
    while (n--) {
        long_t m; scanf("%lld\n", &m);
        node_ptr head = collatz(m);
        for (node_ptr t = head; t != NULL; t = t->next)
            printf("%lld ", t->num);
        printf("\n");
        clean(head);
    }
    printf("finished");
}

node_ptr collatz(long_t n) {
    node_ptr newnode = (node_ptr)malloc(sizeof(struct _node));
    newnode->num = n;
    if (n == 1)
        newnode->next = NULL;
    else if (n % 2 == 0)
        newnode->next = collatz(n / 2);
    else
        newnode->next = collatz(3 * n + 1);
    return newnode;
}
void clean(node_ptr head) {
    node_ptr temp = head;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
    free(temp);
}