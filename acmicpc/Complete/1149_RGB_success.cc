#include<iostream>
#include<string.h>
#define INF 1000000

using namespace std;

int rgb2(int idx, int color);
int min3(int a, int b, int c);

int cache[1001][3], input[1001][3];
int n;

int main(){
    memset(cache, INF, sizeof(cache));
    memset(input, INF, sizeof(input));
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>input[i][0]>>input[i][1]>>input[i][2];
    
    rgb2(-1,-1);
    
    cout<<min3(cache[0][0], cache[0][1], cache[0][2])<<endl;
    
    return 0;
}

int rgb2(int idx, int color){
    
    int &ret=cache[idx][color];
    int in=input[idx][color];
    
    if(cache[idx][color]=!INF)
        return ret;
    
    if(idx==n)
        return 0;
    
    if(idx==-1)
        return ret=min3(rgb2(idx+1, 0)+in, rgb2(idx+1,1)+in, rgb2(idx+1,2)+in);
    else
        return ret=min(rgb2(idx+1, (color+1)%3)+in, rgb2(idx+1, (color+2)%3)+in);
}

int min3(int a, int b, int c){
    return min(min(a,b),c);
}