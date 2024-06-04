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
node_ptr collatz(long_t n) {
    node_ptr ret = create_node(n);
    if (n == 1) {
        return ret;
    }else if (n % 2 == 0) {
        ret->next = collatz(n / 2);
    }
    else {
        ret->next = collatz(3 * n + 1);
    }
    return ret;
}
int length(node_ptr head) {
    node_ptr cur = head;
    int cnt = 0;
    while (cur != NULL) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}
void bubblesort(int n, node_ptr head) {
    for (int i = 0; i < n ; i++) {
        node_ptr cur = head;
        for (int j = 0; j < n - 1-i; j++) {
            if (cur->num > cur->next->num) {
                long_t temp = cur->num;
                cur->num = cur->next->num;
                cur->next->num = temp;
            }
            cur = cur->next;
        }
    }
}

int main()
{
    int n; scanf("%d", &n);
    node_ptr head = collatz(n);
    int len = length(head);
    bubblesort(len, head);
    printf("%d\n", len);
    node_ptr trail = head;
    while (trail != NULL) {
        printf("%llu ", trail->num);
        trail = trail->next;
    }
}
