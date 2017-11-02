#include<iostream>
#include<string.h>

using namespace std;

#define MAX_N 1001
#define MAX 10000

int n;
int color[MAX_N-1][3];
int cache[MAX_N][3];
int rgbcolor(int ind, int pick);

int main()
{
    memset(cache,-1,sizeof(cache));
    memset(color,0, sizeof(color));
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>color[i][j];
    
    cout<<rgbcolor(n,-1)<<endl;
    
    return 0;
}

int rgbcolor(int ind, int pick)
{
    int &ret=cache[ind][pick];
    if(ret!=-1) return ret;
    if(ind==0) return ret=color[ind][pick];
    
    ret=MAX;
    pick=(pick+3)%3;
    
    for(int i=0;i<3;i++){
        if(pick==i) continue;
        ret=min(ret, color[ind][pick]+rgbcolor(ind-1,i));
    }
    return ret;
}