/*
# Page
    117p 121p 122p/ Chapter 3.(Part2) 22p 31p 33p
    http://155.230.120.231/contest/161/problem/AP.6.2
# Name 
    Search Binary Tree
    Optimal Binary Search Tree
    Build Optimal Binary Search Tree
# Description 
    BST 탐색 및 최적이진트리 값 구하기
    key의 개수 n, n개 key의 값, n개의 빈도값 p가 주어진다
# Input
    [n]
    [key[1]] [key[2]] ... [key[n]]
    [p[1]] [p[2]] ... [p[n]]
# Output

# TimeComplexity

*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0xffff
#define swap(x,y,t) (t)=(x),(x)=(y),(y)=(t)
using namespace std;
typedef struct _node{
    int key;
    struct _node* left;
    struct _node* right;
}node;
typedef node* node_ptr;
typedef vector<vector<int>> matrix_t;

//- BST의 탐색한 결과 해당 노드의 주소를 p에 저장, 트리 안에 찾는 key값이 무조건 있다고 가정 
void search(node_ptr tree,int keyin,node_ptr& p){
    bool found;
    p=tree;
    found=false;
    while(!found){
        if(p->key==keyin)
            found=true;
        else if(keyin<p->key)
            p=p->left;
        else
            p=p->right;
    }
}
//- i에서 j까지의 p값 합
int sum(int i,int j,vector<int>& p){
    int sum=0;
    for(int s=i;s<=j;s++)
        sum+=p[s];
    return sum;
}
//- i에서 j까지 k를 거쳤을 때 A[i][j]의 값 중 최솟값을 반환, 해당 k는 ref를 통해 optsearchtree()에서 사용가능
int minimum(int i,int j,int& k,vector<int>& p,matrix_t& A){
    for(int key=i;key<=j;key++){
        int Aval=A[i][key-1]+A[key+1][j]+sum(i,j,p);
        if(A[i][j] > Aval){
            A[i][j]=Aval;
            k=key;
        }
    }
    return A[i][j];
}
/*- A[i][j]=minimum(A[i][k-1]+A[k+1][j])+sum_of_p_range(i:j) : i에서 j까지의 확률 최소값 ,즉 최적이진트리의 value
- R[i][j]=k : i에서 j까지 최소일려면 root는 k, 즉 최적이진트리의 solution*/
void optsearchtree(int n,vector<int>& p,matrix_t& A,matrix_t& R){
    /*A와 R은 상삼각행렬, A의 주대각선은 자신의 빈도p값, R의 주대각선은 스스로 root 값으로 초기화
    주대각선 바로 아래 값은 0으로 초기화*/
    for(int i=1;i<=n;i++){
        A[i][i]=p[i]; A[i][i-1]=0;
        R[i][i]=i; R[i][i-1]=0;
    }
    A[n+1][n]=R[n+1][n]=0;
    
    for(int diagonal=1;diagonal<=n-1;diagonal++)
        for(int i=1;i<=n-diagonal;i++){
            int j=i+diagonal,k;
            A[i][j]=minimum(i,j,k,p,A);
            R[i][j]=k;
        }
}
void preorder(node* root){
    if(root){
        cout<<root->key<<' ';
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->key<<' ';
        inorder(root->right);
    }
}
node* create_node(int newdata){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->key=newdata; newnode->left=NULL; newnode->right=NULL;
    return newnode;
}
//- 최적 이진트리를 만드는 함수
node_ptr tree(int i,int j,vector<int>& keys,matrix_t& R){
    int k=R[i][j];
    if(k==0)
        return NULL;
    else{
        node_ptr node=create_node(keys[k]);
        node->left=tree(i,k-1,keys,R);
        node->right=tree(k+1,j,keys,R);
    }
}
//- key의 값이 정렬되어 주어지지 않는 경우 key와 대응하는 p를 정렬
void sorting(int n,vector<int>& key,vector<int> p){
    for(int i=1;i<=n-1;i++)
        for(int j=i;j<=n;j++)
            if(key[i]>key[j]){
                int temp; 
                swap(key[i],key[j],temp);
                swap(p[i],p[j],temp);
            }
}
int main(){
    int n; cin>>n;
    vector<int> key(n+2),p(n+2);
    for(int i=1;i<=n;i++)
        cin>>key[i];
    for(int i=1;i<=n;i++)
        cin>>p[i];

    sorting(n,key,p);

    matrix_t A(n+2,vector<int>(n+2,INF));
    matrix_t R(n+2,vector<int>(n+2,INF));

    optsearchtree(n,p,A,R);

    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=n;j++)
            if(A[i][j]!=INF) cout<<A[i][j]<<' ';
        cout<<endl;
    }

    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=n;j++)
            if(R[i][j]!=INF) cout<<R[i][j]<<' ';
        cout<<endl;
    }
    cout<<A[1][n]<<endl;

    node* root=tree(1,n,key,R);

    preorder(root);
    cout<<'\n';
    inorder(root);

    return 0;
}