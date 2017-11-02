#include<iostream>
#include<vector>
#include<cstring>
#define MAX_MN 50

using namespace std;

typedef pair<int, int> P;
int T, M, N, K;
int map[MAX_MN][MAX_MN];
int visited[MAX_MN][MAX_MN];
vector<P> dir;

void init();
int dfsAll();
void dfs(int y, int x);

int main(){
    cin>>T;
    int x,y;
    
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(0,-1));
    
    for(int i=0;i<T;i++){
        init();
        cin>>M>>N>>K; // M은 x에 관한 것, N은 y에 관한 것
        for(int j=0;j<K;j++){
            cin>>x>>y;
            map[y][x]=1;
        }
        
        cout<<dfsAll()<<endl;
    }
    
}

void init(){
    memset(visited, 0, sizeof(visited));
    memset(map, 0, sizeof(map));
}

int dfsAll(){
    int ret=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] && !visited[i][j]){
                visited[i][j]=1;
                dfs(i,j);
                ret++;
            }
        }
    }
    
    return ret;
}

void dfs(int y, int x){
    for(int i=0;i<dir.size();i++){
        int next_y=y+dir[i].first, next_x=x+dir[i].second;
        if(next_y>=0 && next_y<N && next_x>=0 && next_x<M){
            if(map[next_y][next_x] && !visited[next_y][next_x]){
                visited[next_y][next_x]=1;
                dfs(next_y, next_x);
            }
        }
    }
}