#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,int> foo;
int main(){
    int n;
    cin>>n;
    string inp;
    while(n--){
        cin>>inp;
        foo[inp]++;
    }

    int maxint=-1;
    string maxstring;
    
    for(auto it=foo.begin();it!=foo.end();it++){
        if(maxint<it->second){
            maxint=it->second;
            maxstring=it->first;
        }
    }
    cout<<maxstring<<' '<<maxint;
    return 0;
}