#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

#define MAX_N 1001

using namespace std;

vector<vector<int> > adj(MAX_N, vector<int>(0));
bool visited[MAX_N];
int N,M;

void dfs(int node);
void dfs_main(int root);
void bfs(int root);

int main(){
    int root;
    int e_start, e_end;
    cin>>N>>M>>root;
    for(int i=0;i<M;i++){
        cin>>e_start>>e_end;
        adj[e_start].push_back(e_end);
        adj[e_end].push_back(e_start);
    }
    /*
    for(int i=1;i<=N;i++){
        for(int j=0;j<adj[i].size();j++){
            //cout<<i<<","<<j<<endl;
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    
    for(int i=1;i<=N;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    
   // cout<<"====="<<endl;
    /*
    for(int i=1;i<=N;i++){
        for(int j=0;j<adj[i].size();j++){
            //cout<<i<<","<<j<<endl;
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
    */
    dfs_main(root);
    cout<<endl;    
    
    memset(visited, 0, sizeof(visited));
    
    bfs(root);/*
    for(int i=1;i<=N;i++)
        if(!visited[i]){
            bfs(i);        
        }
    */
    
}

void dfs(int node){
    
    for(int i=0;i<adj[node].size();i++){
        int next=adj[node][i];
        if(!visited[next]){
            cout<<next<<" ";
            visited[next]=true;
            dfs(next);
        }
    }
}

void dfs_main(int root){
    visited[root]=1;
    cout<<root<<" ";
    dfs(root);
    /*
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            cout<<i<<" ";
            visited[i]=true;
            dfs(i);
        }
    }*/
}

void bfs(int root){
    queue<int> q;
    visited[root]=true;
    q.push(root);
    cout<<root<<" ";
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<adj[cur].size();i++){
            int next=adj[cur][i];
            if(!visited[next]){
                visited[next]=true;
                cout<<next<<" ";
                q.push(next);
            }
        }
    }
}