#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 1001

using namespace std;

// 누가봐도 LIS 문제

int N, ret;
int input[MAX_N], cache[MAX_N];

int lis_box(int idx);

int main(){
    memset(cache, -1, sizeof(cache));
    cin>>N;
    for(int i=1;i<=N;i++) cin>>input[i];
    
    for(int i=1;i<=N;i++){
        ret=max(ret, lis_box(i));
    }
    cout<<ret<<endl;
    return 0;
}

int lis_box(int idx){
    int& ret=cache[idx];
    if(ret!=-1) return ret;
    if(idx==N) return ret=1;
    
    ret=1;
    for(int i=idx+1;i<=N;i++){
        if(input[idx]<input[i]){
            ret=max(ret, lis_box(i)+1);
        }
    }
    return ret;
}