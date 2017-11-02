#include<iostream>
#include<vector>
#include<cstring>
#define MAX 1001

using namespace std;

vector<vector<int> >adj(MAX, vector<int>(0));
bool visited[MAX];
int T,N;

int init();
int dfs(int i);
int dfsAll();

int main(){
    int input;
    cin>>T;
    for(int i=0;i<T;i++){
        init();
        cin>>N;
        for(int j=1;j<=N;j++){
            cin>>input;
            adj[j].push_back(input);
        }
        /*
        for(int i=1;i<=N;i++){
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<"\t";
            }
            cout<<endl;
        }
        */
        cout<<dfsAll()<<endl;
        
    }
    
    return 0;
}

int init(){
    memset(visited, 0, sizeof(visited));
    for(int j=1;j<=N;j++) adj[j].resize(0);
}

int dfs(int node){
    for(int i=0;i<adj[node].size();i++){
        int next=adj[node][i];
        if(!visited[next]){
            visited[next]=true;
            dfs(next);
        }
    }
}

int dfsAll(){
    int ret=0;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            dfs(i);
            ret++;
            
        }
    }
    return ret;
}