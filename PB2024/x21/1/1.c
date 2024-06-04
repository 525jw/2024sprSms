#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node node_t;
typedef struct _node* node_ptr;
struct _node {
    int x, y, z;
    node_ptr next;
};

node_ptr create_node(int x, int y, int z) {
    node_ptr newnode = (node_ptr)malloc(sizeof(newnode));
    newnode->x = x;
    newnode->y = y;
    newnode->z = z;
    newnode->next = NULL;
    return newnode;
}
void insert_node(node_ptr* head, node_ptr node) {
    if (head != NULL)
        node->next = *head;
    *head = node;
}

int main() {
    int n, x, y, z;
    scanf("%d", &n);
    node_ptr head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        node_ptr node = create_node(x, y, z);
        insert_node(&head, node);
    }
    node_ptr trail = head;
    while (trail != NULL) {
        printf("%d %d %d\n", trail->x, trail->y, trail->z);
        trail = trail->next;
    }
}