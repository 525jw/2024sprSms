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
void remove_node(node_t** head, node_t* node);
node_t* find_largest(node_t* head);

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
    for (int i = 0; i < n; i++) {
        node_t* largest = find_largest(head);
        printf("%s %d\n", largest->name, largest->price);
        remove_node(&head, largest);
        free(largest);
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

void remove_node(node_t** head, node_t* node) {
    if (strcmp((*head)->name, node->name) == 0)
        *head = (*head)->next;
    else {
        node_t* prev = NULL;
        node_t* cur = *head;
        while (cur != NULL) {
            if (strcmp(node->name, cur->name) == 0) {
                prev->next = cur->next;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }

}
node_t* find_largest(node_t* head) {
    node_t* large = head;
    node_t* cur = head;
    while (cur != NULL) {
        if (large->price < cur->price)
            large = cur;
        cur = cur->next;
    }
    return large;
}