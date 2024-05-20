#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node node_t;

struct _node {
    char name[20];
    int price;
    node_t* next;
};

node_t* head = NULL;

node_t* create_node(char* name, int price);
void append_node(node_t* node);
node_t* find_largest();

int main()
{
    int n; scanf("%d\n", &n);
    char str[20]; int price;
    for (int i = 0; i < n; i++) {
        scanf("%s %d\n", str, &price);
        node_t* ptr = create_node(str, price);
        if (head == NULL)
            head = ptr;
        else
            append_node(ptr);
    }
    node_t* largest = find_largest();
    printf("%s %d", largest->name, largest->price);
}
node_t* create_node(char* name, int price) {
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    strcpy(newnode->name, name);
    newnode->price = price;
    newnode->next = NULL;
    return newnode;
}
void append_node(node_t* node) {
    node_t* cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = node;
}
node_t* find_largest() {
    node_t* cur = head;
    node_t* maxnode = head;
    maxnode->price = -1;
    while (cur != NULL) {
        if (maxnode->price < cur->price) maxnode = cur;
        cur = cur->next;
    }
    return maxnode;
}