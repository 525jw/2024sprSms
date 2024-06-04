#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long long_t;
typedef struct _node* node_ptr;

struct _node {
    long_t num;
    node_ptr next;
};

node_ptr create_node(long_t n) {
    node_ptr newnode = (node_ptr)malloc(sizeof(struct _node));
    newnode->num = n;
    newnode->next = NULL;
    return newnode;
}
node_ptr modified_collatz(long_t n) {
    node_ptr head = (node_ptr)malloc(sizeof(struct _node));
    head->num = n;
    head->next = NULL;
    node_ptr tail = head;
    while (n != 1) {
        n = (n % 2 == 0) ? n / 2 : 3 * n - 1;

        int flag = 0;
        node_ptr trail = head;
        while (trail) {
            if (trail->num == n) {
                flag = 1;
                break;
            }
            trail = trail->next;
        }
        
        node_ptr node = (node_ptr)malloc(sizeof(struct _node));
        node->num = n;
        node->next = NULL;
        tail->next = node;
        tail = node;
        
        if (flag) {
            break;
        }

    }
    return head;
}
void clean(node_ptr head) {
    node_ptr cur = head;
    node_ptr temp;
    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
}

int main()
{
    int n; scanf("%d", &n);
    while (n--) {
        long_t m; scanf("%llu", &m);
        node_ptr head = modified_collatz(m);
        for (node_ptr t = head; t != NULL; t = t->next)
            printf("%llu ", t->num);
        printf("\n");
        clean(head);
    }
}