/* V E // 1<=V<=20000, 1<=E<=300000
 * K // 1<=K<=V // 시작 정점의 번호
 * u,v,w // u->v, 가중치 w // 0<w<=10
 */
#include<iostream>
#include<vector>
#include<queue>

#define MAX_SIZE 20001
#define INF 10000000

using namespace std;

int V, E, K;
typedef pair<int, int> P;
vector<vector<P> >adj(MAX_SIZE, vector<P>());
int dist[MAX_SIZE];
int visited[MAX_SIZE];

int dijkstra(int root);

class comp{
    public:
        bool operator()(P const &a, P const &b) const {
            return a.second < b.second; // true면 큐의 앞으로 간다.
        }
};

int main(){
    fill(dist, dist+MAX_SIZE, INF);
    fill(visited, visited+MAX_SIZE, false);
    cin>>V>>E>>K;
    int u,v,w;
    
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        adj[u].push_back(P(v,w));
    }
    
    dijkstra(K);
    for(int i=1;i<=V;i++){
        if(dist[i]==INF)
            puts("INF");
        else
            cout<<dist[i]<<endl;
    }
}

int dijkstra(int root){
    // 해당 기점을 root로 하여 나머지까지 가는 최소의 거리를 구한다.
    priority_queue<P, vector<P>, greater<P> >pq; // value가 가장 낮은 것을 우선으로 한다.
    dist[root]=0;
    
    pq.push(P(root, 0));
    
        // 최후 방책이라면 제대로 세워야함
        // 근데 실상 도달하지 않는점이라면 무조건 INF 아닌가?
    while(!pq.empty()){
        int cur=pq.top().first;
        pq.pop();
        
        //visited를 활용해야함. 방문하는지 안하는지.
        if(visited[cur]) continue;
        visited[cur]=true;
        
        for(auto &p: adj[cur]){
            int next=p.first, next_dist=p.second;
            
            if(dist[next] > dist[cur]+next_dist){
                dist[next]=dist[cur]+next_dist;
                pq.push(P(next, next_dist));
            }
        }
    }        

    
}