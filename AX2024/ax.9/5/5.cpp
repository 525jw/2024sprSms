#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    int t=1;
    vector<int> student;
    for(int i=0;i<N;i++)
        student.push_back(i+1);
    /*- N=4
    index  0 1 2 3
    NUM    1 2 3 4
    */
    while(student.size()>1){

        t++;
    }
    return 0;
}