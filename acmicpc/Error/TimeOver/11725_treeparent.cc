/* bfs를 이용해도 시간초과가 걸림
*/
#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int n, a, b;
int parent[100001];
bool visited[100001];
queue<int> q;

void bfs(int idx);
vector<vector<int> >adj(100001, vector<int>(0)); // 마지막을 (0)으로 하든, (0,-1)로 하든 큰 차이는 없음

// bfs를 사용해보기로
int main(){
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    
    cin>>n;
    
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a); // 인접리스트 구현
    }
    
    bfs(1); // bfs로 탐색을 시작한다. bfs로 구현할때는 queue를 사용해야 한다
    for(int i=2;i<=n;i++)
        cout<<parent[i]<<"\n";
}

void bfs(int idx){
    q.push(idx);
    
    while(!q.empty()){ // idx에 종속적으로 가면 안됨
        int here=q.front();
        q.pop();
        for(int i=0;i<adj[here].size();i++){
            int next=adj[here][i];
            if(!visited[next]){
                visited[next]=1;
                parent[next]=here;
                q.push(next);
            }
        }
    }

}