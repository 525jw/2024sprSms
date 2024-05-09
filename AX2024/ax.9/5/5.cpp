#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N;
    cin>>N;
    long long t=1,cur=0;
    vector<long long> student;
    for(long long i=0;i<N;i++)
        student.push_back(i+1);
    while(student.size()>1){
        long long step=t*t*t;
        cur=(cur+(step-1))%student.size();
        student.erase(student.begin()+cur);
        if(cur==student.size())
            cur=0;
        t++;
    }
    cout<<student[cur];
    return 0;
}