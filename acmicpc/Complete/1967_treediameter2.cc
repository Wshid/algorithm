#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n;
vector<vector<int> > adj(10001, vector<int>(0));
vector<vector<int> > dist(10001, vector<int>(0));
vector<int> height(10001, 0);
vector<bool> visited(10001, 0);
int max_length=-1, max_node;

void tree_dfs(int idx);

int main(){
    int idx,c,w;
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>idx>>c>>w;
        adj[idx].push_back(c);
        adj[c].push_back(idx);
        dist[idx].push_back(w);
        dist[c].push_back(w);
    }
    
    tree_dfs(1);
    //cout<<max_node<<" "<<max_length<<endl;
    visited.resize(0);
    visited.resize(10001, 0);
    height.resize(0);
    height.resize(10001, 0);
    max_length=-1;
    
    tree_dfs(max_node);
    cout<<max_length<<endl;
}

void tree_dfs(int idx){
    stack<int> s;
    s.push(idx);
    visited[idx]=1;
    
    while(!s.empty()){
        int here=s.top();
        s.pop();
        for(int i=adj[here].size()-1; i>=0;i--){
            int there=adj[here][i];
            if(!visited[there]){
                visited[there]=1;
                s.push(there);
                height[there]=height[here]+dist[here][i];
                if(height[there]>max_length){
                    max_node=there;
                    max_length=height[there];
                }
            }
        }
    }
}