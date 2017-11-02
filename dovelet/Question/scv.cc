#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 101

using namespace std;


int dir[2][2]={{1,0}, {0,1}};

int N;
int input[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int scv(int y, int x);

int main(){
    memset(input, -1, sizeof(input));
    memset(cache, -1, sizeof(cache));
    
    int ret;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
        }
    }
    
    ret=scv(1,1);
    cout<<ret<<endl;
    /*
    dir[0][0]=0;
    dir[0][1]=1;
    dir[1][0]=1;
    dir[1][1]=0;
    memset(cache, -1, sizeof(cache));
    //cout<<max(ret, scv(1,1))<<endl;
    cout<<scv(1,1)<<endl;*/
    /*
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<cache[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    
    return 0;
}

int scv(int y, int x){
    int& ret=cache[y][x];
    if(ret!=-1) return ret;
    if((y==N) && (x==N)) return ret=input[y][x];
    
    if(y+dir[0][0]<=N && x+dir[0][1]<=N) ret=input[y][x]+scv(y+dir[0][0], x+dir[0][1]);
    if(y+dir[1][0]<=N && x+dir[1][1]<=N) ret=max(ret, scv(y+dir[1][0], x+dir[1][1])+input[y][x]);
    
    return ret;
}