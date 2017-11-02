#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAX_N 100001

using namespace std;
int N, K;
bool visited[MAX_N];
int dist[MAX_N];

void bfs(int root);
bool is_in(int num);

int main(){
    //memset(dist, MAX_N, sizeof(dist));
    for(int i=0; i<=MAX_N;i++){
        dist[i]=MAX_N;
    }
    cin>>N>>K;
    bfs(N);
    
    cout<<dist[K]<<endl;
    return 0;
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root]=1;
    dist[root]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int nexts[3]={cur+1, cur-1, cur*2};
        for(auto &next : nexts){
            if(is_in(next)){
                if(!visited[next] && dist[next]>dist[cur]+1){
                    dist[next]=dist[cur]+1;
                    visited[next]=true;
                    q.push(next);
                }    
            }
        }
    }
    return;
}

bool is_in(int num){
    if((num<0) || (num >= MAX_N)) return false;
    else return true;
}