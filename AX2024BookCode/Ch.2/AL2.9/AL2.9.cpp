/*
# Page
    75p / Chapter 2.(Part2) 32p
    http://155.230.120.231/contest/156/problem/AP.4.2
# Name 
    Large Integer Multiplication
# Description 
    큰 수 곱셈 카라추바X
# Input
    
# Output

# TimeComplexity
    O(n^2)
*/
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> LargeInteger;
int threshold,cnt;
/*- v 라는 정수 배열의 각 숫자를 한자릿수로 만들고 carry를 올려주는 함수
- v의 일의자리는 index 0, index 숫자가 커질수록 자릿수가 커진다*/
void roundup_carry(LargeInteger &v){
    int carry=0;
    for(int i=0;i<v.size();i++){
        v[i]+=carry;
        carry=v[i]/10;
        v[i]=v[i]%10;
    }
    if(carry!=0) 
        v.push_back(carry);
}
void ladd(LargeInteger a,LargeInteger b,LargeInteger &c){
    c.resize(max(a.size(),b.size()));
    fill(c.begin(),c.end(),0);
    for(int i=0;i<c.size();i++){
        if(i<a.size()) c[i]+=a[i];
        if(i<b.size()) c[i]+=b[i];
    }
    roundup_carry(c);
}
void lmult(LargeInteger a,LargeInteger b,LargeInteger &c){
    c.resize(a.size()+b.size()-1);
    fill(c.begin(),c.end(),0);
    for(int i=0;i<a.size();i++) 
        for(int j=0;j<b.size();j++) 
            c[i+j]+=a[i]*b[j];
    roundup_carry(c);
}
//- 10^m만큼 나누는 함수
void div_by_exp(LargeInteger u,int m,LargeInteger &v){
    if(u.size()==0||u.size()<m) 
        v.resize(0);
    else{
        v.resize(u.size()-m);
        fill(v.begin(),v.end(),0);
        copy(u.begin()+m,u.end(),v.begin());
    }
}
// - 10^m만큼 곱하는 함수
void pow_by_exp(LargeInteger u,int m,LargeInteger &v){
    if(u.size()==0) 
        v.resize(0);
    else{
        v.resize(u.size()+m);
        fill(v.begin(),v.end(),0);
        copy(u.begin(),u.end(),v.begin()+m);
    }
}
//- 10^m만큼 나눈 나머지를 구하고 앞자릿수에 남아있는 0을 제거하는 함수
void remove_leading_zeros(LargeInteger& v) {
    while (v.size() != 0 && v.back()==0)
        v.pop_back();
}
// - 10^m만큼 나눈 나머지를 구하는 함수
void rem_by_exp(LargeInteger u,int m,LargeInteger &v){
    if(u.size()==0) 
        v.resize(0);
    else{
        //u.size() can be smaller than m
        int k=m<u.size()?m:u.size();
        v.resize(k);
        copy(u.begin(),u.begin()+k,v.begin());
        remove_leading_zeros(v);
    }
}
void prod(LargeInteger u,LargeInteger v,LargeInteger &r){
    cnt++;
    LargeInteger x,y,w,z;
    LargeInteger t1,t2,t3,t4,t5,t6,t7,t8;
    //- 자릿수
    int n=max(u.size(),v.size());
    if(u.size()==0 || v.size()==0)
        r.resize(0);
    else if(n<=threshold)
        lmult(u,v,r);
    else{
        //prod를 4번 호출 즉 재귀호출이 4번
        int m=n/2;
        div_by_exp(u,m,x); rem_by_exp(u,m,y);
        div_by_exp(v,m,w); rem_by_exp(v,m,z);
        //t2=prod(x,w)*10^(2*m)
        prod(x,w,t1); pow_by_exp(t1,2*m,t2);
        //t6=(prod(x,z)+prod(w,y)) * 10^m
        prod(x,z,t3); prod(w,y,t4); ladd(t3,t4,t5); pow_by_exp(t5,m,t6);
        //r=t2+t6+prod(y,z)
        prod(y,z,t7); ladd(t2,t6,t8); ladd(t8,t7,r);
        
    }
        
}
int main(){
    cin>>threshold;

    LargeInteger u,v,r;

    cin.ignore();
    while(1){
        char inp=cin.get();
        if(inp=='\n') break;
        u.insert(u.begin(),(inp-'0'));
    }
    while(1){
        char inp=cin.get();
        if(inp=='\n'||cin.eof()) break;
        v.insert(v.begin(),(inp-'0'));
    }

    prod(u,v,r);

    cout << cnt << endl;
    for(int i=r.size()-1;i>=0;i--) cout<<r[i];

    return 0;
}