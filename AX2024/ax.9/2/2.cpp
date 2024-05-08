#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
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
typedef priority_queue<node_ptr,vector<node_ptr>,compare> PriorityQueue;
node_ptr create_node(char newsymbol,int newfrequency){
    node_ptr newnode=(node_ptr)malloc(sizeof(node_t));
    newnode->symbol=newsymbol;
    newnode->frequency=newfrequency;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
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
//- make an encoder for each char using the root node of the HuffmanTree
void make_encoder(node_ptr node, string code, map<char,string> &encoder){
    if(node->symbol !='+'){
        encoder[node->symbol]=code;
    }else{
        make_encoder(node->left,code+"0",encoder);
        make_encoder(node->right,code+"1",encoder);
    }
}

void decode(node_ptr root, node_ptr node, string s,int i){
    if(i<=s.length()){
        if(node->symbol!='+'){
            cout<<node->symbol;
            decode(root,root,s,i);
        }else{ //if(node->symbol=='+')
            if(s[i]=='0')
                decode(root,node->left,s,i+1);
            else // if(s[i]=='1')
                decode(root,node->right,s,i+1);
        }
    }
}
void preorder_traversal(node_ptr root){
    if(root){
        cout<<root->symbol<<':'<<root->frequency<<' ';
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
void inorder_traversal(node_ptr root){
    if(root){
        inorder_traversal(root->left);
        cout<<root->symbol<<':'<<root->frequency<<' ';
        inorder_traversal(root->right);
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

    PriorityQueue PQ;
    for(int i=0;i<n;i++)
        PQ.push(create_node(symb[i],frq[i]));
    huffman(n,PQ);

    map<char,string> encoder;
    make_encoder(PQ.top(),"",encoder);

    preorder_traversal(PQ.top());
    cout<<endl;
    inorder_traversal(PQ.top());
    cout<<endl;

    //encode the given text for t1 times using the map 'encoder'
    int t1; cin>>t1;
    string inp,encoded;
    for(int i=0;i<t1;i++){
        inp.clear(); encoded.clear();
        cin>>inp;
        for(int j=0;j<inp.size();j++)
            encoded+=encoder[inp[j]];
        cout<<encoded<<endl;
    }

    //decode the given text for t2 times using the HuffmanTree
    int t2; cin>>t2;
    string decoded;
    for(int i=0;i<t2;i++){
        inp.clear(); decoded.clear();
        cin>>inp;
        decode(PQ.top(),PQ.top(),inp,0);
        cout<<decoded;
        if(i<t2-1) cout<<endl;
    }

    return 0;
}