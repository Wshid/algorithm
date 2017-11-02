#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 501

using namespace std;

typedef pair<int, int> P;

vector<P> dir;
int input[MAX_N][MAX_N], cache[MAX_N][MAX_N];
int N;

int drop_panda(int y, int x);

int main(){
    int ret=-1;
    memset(input, -1, sizeof(input));
    memset(cache, -1, sizeof(cache));
    
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(0,-1));
    
    cin>>N;
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>input[i][j];
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
           ret=max(ret, drop_panda(i, j)); 
        }
    }
    
    cout<<ret<<endl;
    
    return 0;
}

int drop_panda(int y, int x){
    int& ret=cache[y][x];
    if(ret!=-1) return ret;
    
    
    ret=1;
    for(int i=0;i<dir.size();i++){
        int next_y=y+dir[i].first, next_x=x+dir[i].second;
        
        if(next_y>0 && next_y<=N && next_x>0 && next_y<=N){
            if(input[next_y][next_x] > input[y][x])
                ret=max(ret, drop_panda(next_y, next_x)+1);
        }
    }
    return ret;
    
}