#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node node_t;

struct _node {
    char* name;
    int price;
    node_t* next;
};

node_t* create_node(char* name, int price);
void append_node(node_t** head, node_t* node);
void bubblesort(int n, node_t* head);

int main()
{
    int n; scanf("%d\n", &n);
    char str[20]; int price;
    node_t* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%s %d\n", str, &price);
        node_t* ptr = create_node(str, price);
        append_node(&head, ptr);
    }
    bubblesort(n, head);
    node_t* trail = head;
    while (trail != NULL) {
        printf("%s %d\n", trail->name, trail->price);
        trail = trail->next;
    }
}

node_t* create_node(char* name, int price) {
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->name = (char*)malloc(strlen(name) + 1);
    strcpy(newnode->name, name);
    newnode->price = price;
    newnode->next = NULL;
    return newnode;
}
void append_node(node_t** head, node_t* node) {
    if (*head == NULL)
        *head = node;
    else {
        node_t* cur = *head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
    }
}
void bubblesort(int n, node_t* head) {
    for (int i = 0;i < n-1;i++) {
        node_t* cur = head;
        for (int j = 0;j < n-1 - i;j++) {
            if (cur->price < cur->next->price) {
                char* tempname = cur->name;
                cur->name = cur->next->name;
                cur->next->name = tempname;

                int tempprice = cur->price;
                cur->price = cur->next->price;
                cur->next->price = tempprice;
            }
             cur = cur->next;
        }
    }
}