#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> sequence_of_integer;

bool is_feasible(sequence_of_integer& K,sequence_of_integer& deadline){
    for(int i=1;i<K.size();i++){
        if(i>deadline[K[i]])
            return false;
    }
    return true;
} 
void schedule(int n,sequence_of_integer& deadline,sequence_of_integer &J){
    /*- K=J with i added according to nondecreasing values of deadline[i] 
    - i.e. K is candidate set of indices to search for*/
    sequence_of_integer K;
    
    // let J=[1], first (sorted) Job must be included
    J.clear();
    J.push_back(0);
    J.push_back(1);

    for(int i=2;i<=n;i++){
        K.resize(J.size());
        copy(J.begin(),J.end(),K.begin());

        // add a new i into K according to nondecreasing values of deadline[i]
        int j=1;
        while(j<K.size() && deadline[K[j]]<=deadline[i])
            j++;
        K.insert(K.begin()+j,i);

        if(is_feasible(K,deadline)){
            J.resize(K.size());
            copy(K.begin(),K.end(),J.begin());
        }
    }
}
int main(){
    int n;
    cin>>n;
    sequence_of_integer deadline(n+1);
    for(int i=1;i<=n;i++)
        cin>>deadline[i];
    sequence_of_integer profit(n+1);
    for(int i=1;i<=n;i++)
        cin>>profit[i];
    //- feasible set(solution)
    sequence_of_integer J;
    schedule(n,deadline,J);
    
    int solval=0;
    for(int i=1;i<J.size();i++)
        solval+=profit[J[i]];
    cout<<solval<<endl;
    for(int i=1;i<J.size();i++){
        cout<<profit[J[i]];
        if(i<J.size()-1) cout<<' ';
    }
    return 0;
}