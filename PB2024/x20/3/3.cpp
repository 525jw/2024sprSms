#include <iostream>
#include <map>
using namespace std;

void word_count(map<string, int> &mymap, string str){
    if(mymap.find(str)==mymap.end())
        mymap[str]=1;
    else{
        mymap[str]++;
    }
}
string most_frequent(map<string, int> mymap, int &freq){
    string ret;
    freq=-1;
    for(auto it=mymap.begin();it!=mymap.end();it++){
        if(freq<it->second){
            freq=it->second;
            ret=it->first;
        }
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;

    map<string, int> mymap;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        word_count(mymap, str);
    }

    int freq = 0;
    cout << most_frequent(mymap, freq) << endl;
    cout << freq << endl;
}