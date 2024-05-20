#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node node_t;

struct _node {
    char *name;
    int price;
    node_t *next;
};

node_t *create_node(char *name, int price);
void append_node(node_t **head, node_t *node);
node_t *find_second(node_t *head);

int main()
{
    int n; scanf("%d\n", &n);
    char str[20]; int price;
    node_t *head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%s %d\n", str, &price);
        node_t *ptr = create_node(str, price);
        append_node(&head, ptr);
    }
    node_t *second = find_second(head);
    printf("%s %d", second->name, second->price);
}

node_t* create_node(char* name, int price) {
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->name=(char*)malloc(strlen(name)*sizeof(char)+1);
    strcpy(newnode->name,name);
    newnode->price = price;
    newnode->next = NULL;
    return newnode;
}
void append_node(node_t **head, node_t *node){
    node_t* cur = *head;
    if(*head==NULL) *head=node;
    else{
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
    }
}
node_t *find_second(node_t *head){
    node_t* cur = head;
    node_t* maxnode = head;
    while (cur != NULL) {
        if (maxnode->price < cur->price) maxnode = cur;
        cur = cur->next;
    }
    maxnode->price=-1;
    maxnode=head;
    while (cur != NULL) {
        if (maxnode->price < cur->price) maxnode = cur;
        cur = cur->next;
    }
    return maxnode;
}