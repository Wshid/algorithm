#include<iostream>
#include<cstring>
#include<vector>
#define MAX_N 1001
#define MOD 10007

using namespace std;

//bool map[2][MAX_N];
int cache[MAX_N];
int N;

int tiling(int idx);

int main(){
    memset(cache, -1, sizeof(cache));
    cin>>N;
    cout<<tiling(0)<<endl;
    return 0;
}

int tiling(int idx){
    int& ret=cache[idx];
    if(ret!=-1) return ret;
    
    if(idx==N) return ret=1;
    
    ret=0;
    ret=(ret+tiling(idx+1))%MOD;
    if(idx+2<=N)
        ret=(ret+tiling(idx+2))%MOD;
    
    return ret%MOD;
    
}