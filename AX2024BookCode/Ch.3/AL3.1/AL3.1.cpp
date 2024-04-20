/*
# Page
    93p / Chapter 3.(Part1) 10p
# Name 
    Binomial Coefficient Using Dvide-and-Conquer
# Description 
    Tree의 노드 개수 만큼 시간복잡도가 나온다. 높이는 worst case에서 n
# Input

# Output

# TimeComplexity
    O(2^n)
*/
#include <iostream>
using namespace std;
typedef unsigned long long LongInteger;

LongInteger bin(int n,int k){
    if(k==0 || n==k)
        return 1;
    else
        return bin(n-1,k)+bin(n-1,k-1);
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<bin(n,k);
    return 0;
}