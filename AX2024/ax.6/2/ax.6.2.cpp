#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
#define INF 9999999
#define spacebar ' '
#define endl '\n'
typedef struct vector<vector<int>> matrix;
typedef struct _node{
    int data;
    struct _node* left;
    struct _node* right;
}node;
int solve(int i,int j,vector<int> prob,matrix& A,matrix& R){
    //cout<<i<<' '<<j<<endl;
    if(A[i][j]!=-1) return A[i][j];
    else if(i==j) {R[i][j]=i; return A[i][j]=prob[i];}
    else if(i>j) {R[i][j]=0; return A[i][j]=0;}
    else{
        int minval=INF;
        for(int k=i;k<=j;k++){ 
            //cout<<'#'<<i<<' '<<k-1<<' '<<k+1<<' '<<j<<endl;
            int nowval=solve(i,k-1,prob,A,R)+solve(k+1,j,prob,A,R);
            minval=(minval>nowval) ? R[i][j]=k,nowval : minval;
        }
        for(int k=i;k<=j;k++)
            minval+=prob[k];
        return A[i][j]=minval;
    }
}
node* create_node(int newdata){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=newdata;
    return newnode;
}
node* create_tree(vector<int> key,matrix& R,int i,int j){
    node* root=create_node(key[R[i][j]]);
    if(R[i][j]-1>=i) root->left=create_tree(key,R,i,R[i][j]-1);
    else root->left=NULL;
    if(R[i][j]+1<=j) root->right=create_tree(key,R,R[i][j]+1,j);
    else root->right=NULL;
    return root;
}
void preorder(node* root,int& whitespacenooooooo){
    cout<<root->data; if(--whitespacenooooooo) cout<<spacebar;
    if(root->left) preorder(root->left,whitespacenooooooo);
    if(root->right) preorder(root->right,whitespacenooooooo);
}
void inorder(node* root,int& whitespacenooooooooo){
    if(root->left) inorder(root->left,whitespacenooooooooo);
    cout<<root->data; if(--whitespacenooooooooo) cout<<spacebar;
    if(root->right) inorder(root->right,whitespacenooooooooo);
}
int main(){
    int n; cin>>n;
    vector<int> key(n+2),prob(n+2);
    for(int i=1;i<=n;i++)
        cin>>key[i];
    for(int i=1;i<=n;i++)
        cin>>prob[i];
    matrix A(n+2,vector<int>(n+2,-1));
    matrix R(n+2,vector<int>(n+2,-1));

    int res=solve(1,n,prob,A,R);

    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=n;j++)
            if(A[i][j]!=-1) {cout<<A[i][j]; if(j!=n) cout<<spacebar;}
        cout<<endl;
    }

    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=n;j++)
            if(R[i][j]!=-1) {cout<<R[i][j]; if(j!=n) cout<<spacebar;}
        cout<<endl;
    }
    cout<<res<<endl;

    node* tree=create_tree(key,R,1,n);

    int whitespacenooooo=n;
    preorder(tree,whitespacenooooo);
    cout<<'\n';
    whitespacenooooo=n;
    inorder(tree,whitespacenooooo);

    return 0;
}