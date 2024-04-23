/*
# Page
    http://155.230.120.231/contest/164/problem/AP.7.4
# Name 
    회의실 배정
# Description 
    N개의 회의 시작시각과 종료시각을 통해 회의의 최대 개수 T와 이 때 개최할 회의를 출력
# Input
    [N]
    [start0] [end0]
    [start1] [end1]
    ... 
    [start(N-1)] [end(N-1)]
# Output

# TimeComplexity
    O(nlogn)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> schedule;

int compare(schedule a,schedule b){
    return a.second<b.second;
}
int main()
{
	int N;
    cin>>N;
    int t_start,t_end;
    vector<schedule> sch;
    for(int i=0;i<N;i++){
        cin>>t_start>>t_end;
        sch.push_back(make_pair(t_start,t_end));
    }
    
    sort(sch.begin(),sch.end(),compare);
    
    vector<schedule> sch_selected;
    int last_end_time=-1;
    for(int i=0;i<sch.size();i++){
        if(sch[i].first>=last_end_time) {
            sch_selected.push_back(sch[i]);
            last_end_time=sch[i].second;
        }
    }
    cout<<sch_selected.size()<<endl;
    for(int i=0;i<sch_selected.size();i++){
        cout<<sch_selected[i].first<<' '<<sch_selected[i].second;
        if(i!=sch_selected.size()-1) cout<<endl;
    }
	return 0;
}