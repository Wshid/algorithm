// 위상정렬을 굳이 안써도 됨. DP로 해결
#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 1001

using namespace std;

int T, N, K, X, Y, W, D;

int build[MAX_N];
vector<vector<int> > adj(MAX_N, vector<int>(0));
bool visited[MAX_N];

int cache[MAX_N];

//int dfs_all();
//int dfs(int node);
int craft(int node);

int main(){
    int b1,b2;
    int subject;
    N=1;
    
    
    cin>>T;
    for(int t=0;t<T;t++){
        memset(cache, -1, sizeof(cache));
        memset(build, 0, sizeof(build));
        for(int i=1;i<=N;i++){
            adj[i].resize(0);
        }
        cin>>N>>K;
        for(int i=1;i<=N;i++)
            cin>>build[i];
            
        for(int i=0;i<K;i++){
            cin>>b1>>b2;
            adj[b2].push_back(b1); // reverse
        }
        
        cin>>subject;
        cout<<craft(subject)<<endl;
        
    }
    
    //for(int i=1;i<=N;i++) cout<<cache[i]<<"\t";
    return 0;
}


int craft(int node){
    int& ret=cache[node];
    if(ret!=-1) return ret;

    //cout<<node<<endl;
    if(adj[node].size()==0) return ret=build[node];
    
    ret=0;
    for(int i=0; i<adj[node].size();i++){
        int next=adj[node][i];
        ret=max(ret, craft(next));
    }
    return ret+=build[node];
}

/*
int dfs_all(){
    for(int i=1;i<=N;i++){
        if(!visited[i])
            dfs(i);
            cout<<i<<"\t";
    }
    return 0;
}

int dfs(int node){
    for(int i=0;i<adj[node].size();i++){
        int next=adj[node][i];
        if(!visited[next]){
            visited[next]=1;
            dfs(next);
        }
    }
}*/