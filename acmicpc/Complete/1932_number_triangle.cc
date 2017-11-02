#include<iostream>
#include<string.h>

using namespace std;

int tri(int idx, int num);

int cache[500][500], input[500][500];
int n;

int main(){
    memset(cache, -1, sizeof(cache));
    memset(input, -1, sizeof(input));
    
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<i+1;j++)
            cin>>input[i][j];
    
    tri(0,0);
    cout<<cache[0][0]<<endl;
    
    return 0;
}

int tri(int idx, int num){
    if(idx==n) return 0;
    
    int& ret=cache[idx][num];
    int in=input[idx][num];
    
    if(ret!=-1) return ret;
    
    // 넘어가는 수가 될 것
    
    return ret=max(tri(idx+1, num)+in, tri(idx+1, num+1)+in);
}