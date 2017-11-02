/* 틀렸다고 나옴 */
#include<iostream>
#include<cstring>
#define MAX_N 301
#define INF 100000000
using namespace std;

int N,M;
int cache[MAX_N][MAX_N];
int split(int n, int m);

int main(){
    memset(cache, -1, sizeof(cache));
    cin>>N>>M;
    cout<<split(N,M)<<endl;
    return 0;
}

int split(int n, int m){
    int& ret=cache[n][m];
    int temp=INF;
    if(ret!=-1) return ret;
    if(n==1 && m==1) return ret=0;
    ret=0;
    
    if(n>1) temp=min(temp,(1+split(n-1,m)+split(n-(n-1),m)));
    
    if(m>1) temp=min(temp, (1+split(n,m-1)+split(n,m-(m-1))));
    
    return ret+=temp;
}