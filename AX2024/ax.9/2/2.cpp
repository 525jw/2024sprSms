#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef struct node* node_ptr;
typedef struct node{
    char symbol;
    int frequency;
    node_ptr left;
    node_ptr right;
}node_t;
struct compare{
    bool operator()(node_ptr p,node_ptr q){
        return p->frequency > q->frequency;
    }
};
node_ptr create_node(char newsymbol,int newfrequency){
    node_ptr newnode=(node_ptr)malloc(sizeof(node_t));
    newnode->symbol=newsymbol;
    newnode->frequency=newfrequency;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
typedef priority_queue<node_ptr,vector<node_ptr>,compare> PriorityQueue;
void huffman(int n,PriorityQueue& PQ){
    for(int i=1;i<=n-1;i++){
        // pop the highest two values
        node_ptr p=PQ.top(); PQ.pop();
        node_ptr q=PQ.top(); PQ.pop();
        node_ptr r=create_node('+',p->frequency+q->frequency);
        r->left=p;
        r->right=q;
        PQ.push(r);
    }
}

int main(){
    int n; cin>>n;
    vector<char> symb(n+1);
    vector<int> frq(n+1);
    for(int i=0;i<n;i++)
        cin>>symb[i];
    for(int i=0;i<n;i++)
        cin>>frq[i];
    int t1; cin>>t1;

    for(int i=0;i<n;i++)
        PriorityQueue.push(create_node(symb[i],frq[i]));






    vector<string> str_to_encode(n+1);
    for(int i=0;i<t1;i++)
        cin>>str_to_encode[i];
    int t2; cin>>t2;
    vector<string> str_to_decode(n+1);
    for(int i=0;i<t2;i++)
        cin>>str_to_decode[i];



    return 0;
}