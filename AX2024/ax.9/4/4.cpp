#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
int romeToArab(string inp){
    //- Normal case
    static map<string,int> romeNumber={
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
    };
    //- Small number before large number case
    static map<string,int> romeNumberException={
        {"IV", 4}, 
        {"IX", 9}, 
        {"XL", 40}, 
        {"XC", 90}, 
        {"CD", 400}, 
        {"CM", 900}
    };
    int ret=0;
    while(inp.size()){
        //The first two chars are in romeNumberException
        if(romeNumberException.find(inp.substr(0,2)) != romeNumberException.end()){
            ret+=romeNumberException[inp.substr(0,2)];
            inp.erase(0,2);
        }else{ // The first char are in romeNumber
            ret+=romeNumber[inp.substr(0,1)];
            inp.erase(0,1);
        }
    }
    return ret;
}
string arabToRome(int inp){
    string ret="";
    for(int i=0;i<3 && inp>=1000;i++,inp-=1000)
        ret+='M';
    if(inp>=900){
        ret+="CM";
        inp-=900;
    }else if(inp>=500){
        ret+="D";
        inp-=500;
    }else if(inp>=400){
        ret+="CD";
        inp-=400;
    }
    for(int i=0;i<3 && inp>=100;i++,inp-=100)
        ret+='C';
    if(inp>=90){
        ret+="XC";
        inp-=90;
    }else if(inp>=50){
        ret+="L";
        inp-=50;
    }else if(inp>=40){
        ret+="XL";
        inp-=40;
    }
    for(int i=0;i<3 && inp>=10;i++,inp-=10)
        ret+="X";
    if(inp>=9){
        ret+="IX";
        inp-=9;
    }else if(inp>=5){
        ret+="V";
        inp-=5;
    }else if(inp>=4){
        ret+="IV";
        inp-=4;
    }
    for(int i=0;i<3 && inp>=1;i++,inp-=1)
        ret+="I";
    return ret;
}
int main(){
    string inp;
    cin>>inp;
    int otp=romeToArab(inp);
    
    //Sieve of Eratosthenes
    vector<bool> primeTable(otp+1,true);
    primeTable[0]=false;
    primeTable[1]=false;
    for(int i=2;i<=sqrt(otp);i++)
        for(int j=2;j<=sqrt(otp);j++)
            primeTable[i*j]=false;
    
    //Finding prime number
    vector<int> answer;
    int temp=otp;
    while(temp>1){
        for(int i=2;i<=otp;i++)
            if(primeTable[i] && temp%i==0) {
                answer.push_back(i);
                temp/=i;
                break;
            } 
    }
    
    for(int i=0;i<answer.size();i++){
        cout<<arabToRome(answer[i]);
        if(i<answer.size()-1) cout<<endl;
    }
    return 0;
}