#include<iostream>
#include<string.h>

#define MOD 1000000000

using namespace std;

int n;
int cache[101][10];

int stair_num(int step, int num);

int main(){
    int result=0;
    memset(cache, -1, sizeof(cache));
    
    cin>>n;
    
    for(int i=1;i<=9;i++){
        stair_num(n,i);
        result=(result+cache[n][i])%MOD;
    }
    
    cout<<result<<endl;
    
    return 0;
}

int stair_num(int step, int num){
    int& ret=cache[step][num];
    
    if(ret!=-1) return ret;
    if(step==1) return ret=1;
    
    if(num==9) return ret=stair_num(step-1, num-1)%MOD;
    else if(num==0) return ret=stair_num(step-1, num+1)%MOD;
    else return ret=(stair_num(step-1, num-1)%MOD + stair_num(step-1, num+1)%MOD)%MOD;
}