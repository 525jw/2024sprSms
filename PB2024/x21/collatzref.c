#include <stdio.h>
#include <stdlib.h>
typedef long long long_t;
typedef struct _node* node_ptr;
typedef struct _node node_t;
struct _node{
    long_t num;
    node_ptr next;
};


int find(node_ptr head,long_t num){
    node_ptr trail=head;
    while(!trail){
        if(trail->num==num)
            return 1;
        trail=trail->next;
    }
    return 0;
}

node_ptr collatz(long_t num){
    node_ptr head=(node_ptr)malloc(sizeof(node_t));
    head->num=num;
    head->next=NULL;
    node_ptr tail=head;
    while(num!=1){
        int flag=0;
        node_ptr trail=head;
        while(!trail){
            if(trail->num==num){
                flag=1;
                break;
            }
            trail=trail->next;
        }           
        if(find(head,num)){
            break;
        }

        num=(num%2==0)?num/2:3*num-1;
        node_ptr node=(node_ptr)malloc(sizeof(node_t));
        node->num=num;
        node->next=NULL;
        tail->next=node;
        tail=node;


    }
    return head;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        long_t x;
        scanf("%llu",&x);
        node_ptr head=collatz(x);
        node_ptr trail=head;
        while(trail){
            printf("%lld",trail->num);
            trail=trail->next;
        }
    }
    return 0;
}