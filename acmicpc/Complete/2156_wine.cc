#include<iostream>
#include<string.h>

using namespace std;

int n;
int input[10001], cache[10001][3];

int wine(int idx, int seq);

int main(){
    memset(cache, -1, sizeof(cache));
    memset(input, -1, sizeof(input));
    
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>input[i];
    
    wine(1,0);
    
    cout<<cache[1][0]<<endl;
    
    return 0;
}

int wine(int idx, int seq){
    int& ret=cache[idx][seq];
    
    if(ret!=-1) return ret;
    
    if(idx>n) return 0;
    
    if(seq==2) return ret=wine(idx+1,0);
    else return ret=max(wine(idx+1, seq+1)+input[idx], wine(idx+1,0));
}