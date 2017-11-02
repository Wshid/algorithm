#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int> > adj(100001, vector<int>(0));
vector<vector<int> > dist(100001, vector<int>(0));
vector<int> height(100001, 0);
vector<bool> visited(100001, false);
int n,idx,child,cost;
int longest=-1;


int stack_dfs(int idx);

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>idx;
        while(1){
            cin>>child;
            if(child==-1) break;
            cin>>cost;
            adj[idx].push_back(child);
            dist[idx].push_back(cost);
        }
    }

    int next_root=stack_dfs(1);
    
    visited.resize(0);
    visited.resize(100001, false);
    height.resize(0);
    height.resize(100001, 0);
    longest=-1;
    stack_dfs(next_root);
    cout<<longest<<endl;
    
}

int stack_dfs(int idx){
    stack<int> s;
    s.push(idx);
    visited[idx]=true;
    int distant_node=-1;
    while(!s.empty()){
        int here=s.top();
        s.pop();
        for(int i=adj[here].size()-1;i>=0;i--){
            int child=adj[here][i];
            if(!visited[child]){
                visited[child]=true;
                height[child]=height[here]+dist[here][i];
                if(height[child]>longest){
                    longest=height[child];
                    distant_node=child;
                }
                s.push(child);
            }
        }
    }
    return distant_node;
}