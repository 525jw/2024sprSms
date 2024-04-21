#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> LargeInteger;
int threshold,cnt;
void roundup_carry(LargeInteger &v){
    int cry=0;
    for(int i=0;i<v.size();i++){
        v[i]+=cry;
        cry=v[i]/10;
        v[i]=v[i]%10;
    }
    if(cry!=0) v.push_back(cry);
}
void add(LargeInteger u,LargeInteger v,LargeInteger &r){
    r.resize(max(u.size(),v.size()));
    fill(r.begin(),r.end(),0);
    for(int i=0;i<r.size();i++){
        if(i<u.size()) r[i]+=u[i];
        if(i<v.size()) r[i]+=v[i];
    }
    roundup_carry(r);
    u.clear();v.clear();
}
void lmult(LargeInteger u,LargeInteger v,LargeInteger &r){
    r.resize(u.size()+v.size()-1);
    fill(r.begin(),r.end(),0);
    int i,j;
    for(i=0;i<u.size();i++) for(j=0;j<v.size();j++) r[i+j]+=u[i]*v[j];
    roundup_carry(r);
    u.clear();v.clear();
}
void pow(LargeInteger u,int m,LargeInteger &v){
    if(u.size()==0) v.resize(0);
    else{
        v.resize(u.size()+m);
        fill(v.begin(),v.end(),0);
        copy(u.begin(),u.end(),v.begin()+m);
    }
    u.clear();
}
void div_by_exp(LargeInteger u,int m,LargeInteger &v){
    if(u.size()==0||u.size()<m) v.resize(0);
    else{
        //cout<<u.size()<<' '<<m<<endl;
        v.resize(u.size()-m);
        fill(v.begin(),v.end(),0);
        copy(u.begin()+m,u.end(),v.begin());
    }
    u.clear();
}
void remove_leading_zeros(LargeInteger& v) {
    while (v.size() != 0 && v.back()==0)
        v.pop_back();
}
void rem_by_exp(LargeInteger u,int m,LargeInteger &v){
    if(u.size()==0) v.resize(0);
    else{
        int k=m<u.size()?m:u.size();
        v.resize(k);
        copy(u.begin(),u.begin()+k,v.begin());
        remove_leading_zeros(v);
    }
    u.clear();
}
void prod(LargeInteger u,LargeInteger v,LargeInteger &r){
    cnt++;
    LargeInteger x,y,w,z;
    LargeInteger t1,t2,t3,t4,t5,t6,t7,t8;
    int n=max(u.size(),v.size());
    if(u.size()==0 || v.size()==0)
        r.resize(0);
    else if(n<=threshold)
        lmult(u,v,r);
    else{
        int m=n/2;
        div_by_exp(u,m,x); rem_by_exp(u,m,y);
        div_by_exp(v,m,w); rem_by_exp(v,m,z);
        prod(x,w,t1); pow(t1,2*m,t2);

        prod(x,z,t3); prod(w,y,t4); add(t3,t4,t5); pow(t5,m,t6);
        prod(y,z,t7); add(t2,t6,t8); add(t8,t7,r);
    }
    u.clear();v.clear();
    x.clear();y.clear();w.clear();z.clear();
    t1.clear();t2.clear();t3.clear();t4.clear();t5.clear();t6.clear();t7.clear();t8.clear();
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