#include<iostream>
#include<vector>
#include<cstring>

#define MAX_N 101
#define INF 100000

using namespace std;

typedef pair<int, int> P;
vector<P> dir;

int N,M; // 2<=M,N<=100
int input[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int maze(int y, int x, int new_dir);

int main(){
    char temp;
    int answer=INF;
    memset(cache, -1, sizeof(cache));
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(0,-1));

    cin>>N>>M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>temp;
            input[i][j]=(int)temp-48;
        }
    }
    
    
    //visited[1][1]=true;
    for(int i=0;i<4;i++){
        memset(visited, 0, sizeof(visited));
        memset(cache, -1, sizeof(cache));
        answer=min(answer, maze(1,1, i));
    }
    
    cout<<answer<<endl;
    
    /*
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<cache[i][j]<<"\t";
        }
        cout<<endl;
    }
    */
    
    return 0;
}

int maze(int y, int x, int new_dir){
    int& ret=cache[y][x];
    if(ret!=-1) return ret; // maze를 반복해서 돌리면되지 않을까?
    if(visited[y][x]) return ret;
    
    if(y==N && x==M) return ret=1; // 여기가 바뀌어야 됨 무조건 0이됨
    
    visited[y][x]=true;
    
    ret=INF;
    for(int i=new_dir;i<dir.size()+new_dir;i++){
        int k=i%4;
        int next_y=y+dir[k].first;
        int next_x=x+dir[k].second;
        
        if(next_y>=1 && next_y <=N && next_x>=1 && next_x<=M){
            if((input[next_y][next_x]==1) && (!visited[next_y][next_x])){
                ret=min(ret, maze(next_y, next_x, new_dir)+1);
            }
        }
    }
    visited[y][x]=false;
    
    return ret;
}