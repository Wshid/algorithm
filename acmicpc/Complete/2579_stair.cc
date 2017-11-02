#include<iostream>
#include<string.h>

#define INF -10000

using namespace std;

int cache[301][3];
int input[301];
int n;

int sta(int idx, int step);
int max3(int a, int b, int c);

int main(){
    memset(cache, -1, sizeof(cache));
    memset(input, -1, sizeof(input));
    
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>input[i];
    cache[0][0]=max(sta(1,0), sta(2,0));
    input[0]=0;
    
    cout<<cache[0][0]<<endl;

    return 0;
}

int sta(int idx, int step){
    int &ret=cache[idx][step];
    int &in=input[idx];
    
    if(ret!=-1) return ret;
    if(idx==n && step!=2) return input[n];
    if(idx>n) return INF;
    
    switch(step){
        case 0:
            ret=max(sta(idx+1, step+1), sta(idx+2, 0))+in;
            break;
        case 1:
            ret=max(sta(idx+1, step+1), sta(idx+2, 0))+in;
            break;
        case 2:
            ret=sta(idx+1, 0);
            break;
        default:
            return INF;
    }
    return ret;
}

int max3(int a, int b, int c){
    return max(max(a,b),c);
}