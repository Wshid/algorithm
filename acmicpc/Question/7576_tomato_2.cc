/* 2퍼센트 정도에서 틀렸다고 나옴 */
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX_N 1001
#define INF 1000000

using namespace std;

int M,N;
int map[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
typedef pair<int, int> P;
vector<P> dir;

int mature(int y, int x);
bool is_in(int y, int x);

int main(){
    
    int ret=0;
    cin>>M>>N;
    
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            map[i][j]=-1;
            
    for(int i=1;i<=N;i++){//dist가 전혀 초기화 되지 않음
        for(int j=1;j<=M;j++){
            dist[i][j]=INF;
        }
    }
            
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(0,-1));
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>map[i][j];
    

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(!visited[i][j] && map[i][j]==1){
                //cout<<"IN"<<endl;
                ret=max(ret, mature(i,j));
            }
            
        /* TEST CODE */
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    if(ret==0){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(!visited[i][j]){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }        
    }
    else{
        cout<<ret<<endl;    
    }
    return 0;
}

int mature(int y, int x){
    queue<P> q;
    q.push(make_pair(y, x));
    visited[y][x]=1;
    int ret=0;
    dist[y][x]=0;
    
    while(!q.empty()){
        P cur=q.front();
        int cur_y=cur.first;
        int cur_x=cur.second;
        q.pop();
        
        for(int i=0;i<dir.size();i++){
            int next_y=cur_y+dir[i].first;
            int next_x=cur_x+dir[i].second;
            
            if(is_in(next_y, next_x)){
                if(map[next_y][next_x]==-1){
                    visited[next_y][next_x]=1;
                    dist[next_y][next_x]=0;
                    //cout<<"FCON"<<endl;
                }
                else{
                    if(!map[next_y][next_x] && (dist[next_y][next_x]>dist[cur_y][cur_x]+1) && !visited[next_y][next_x]){
                        dist[next_y][next_x]=dist[cur_y][cur_x]+1;
                        visited[next_y][next_x]=1;
                        q.push(make_pair(next_y, next_x));
                    }
                    //cout<<"ELSE"<<endl; // 여기서 무한루프
                }
            }
            //cout<<"LOL"<<endl; // 무한 루프 돈다.
            
        }
    }
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(dist[i][j]!=INF)
                ret=max(ret, dist[i][j]);
    
    return ret;
}

bool is_in(int y, int x){
    if(y<1 || y>N || x<1 || x>M) return false;
    else return true;
}