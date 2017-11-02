#include<iostream>
#include<queue>
#include<vector>
#define MAX_N 10

using namespace std;

BFS_인접 리스트(adjacent_list)
vector<vector<int> >adj(MAX_N, vector<int>(0));

vector<int> bfs(int start){
    vector<bool> discovered(adj.size(), false);
    
    queue<int> q;
    vector<int> order;
    discovered[start]= true;
    q.push(start);
    while(!q.empty()){
        int here=q.front();
        q.pop();
        
        for(int i=0;i<adj[here].size();i++){
            int there=adj[here][i];
            if(!discovered[there]){
                q.push(there);
                discovered[there]=true;
            }
        }
    }
    return order;
}