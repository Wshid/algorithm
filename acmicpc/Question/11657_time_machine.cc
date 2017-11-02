// 벨만 포드 알고리즘의 전형적인 문제
#include<iostream>
#include<vector>

#define INF 10000000

using namespace std;
typedef pair<int, int> P;
vector<vector<P> >adj(501, vector<P>()); // 에러나지 않음
int ret[501]; // 결과값을 저장할 배열


int n,m; // n은 vertex, m은 edge 수

int main(){
    int a,b,dis;
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>dis;
        adj[a].push_back(make_pair(b,dis));
    }
    
    /* input test code */
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++)
            cout<<adj[i][j].first<<","<<adj[i][j].second<<"\t";
        cout<<endl;
    }
}

int bellman(){
    fill(ret, ret+501,INF);
    ret[1]=0;
    int minusCycle=false;
    for(int i=0;i<=n;i++){ // 단순 반복용
        for(int j=1;j<=n;j++){
            for(auto &p: adj[j]){ //python with과 같은 문법인듯
                int next=p.first, distance=p.second;
                if(ret[j]!=INF && ret[next]>ret[j]+distance){
                    ret[next]=ret[j]+distance;
                        if(i==n-1) minusCycle=true;
                }
            }
        }
    }
    if(minusCycle==true)
        puts("-1");
    else{
        for(int i=1; i<=n; i++){
            cout<<(ret[i]!=INF? ret[i] : -1)<<endl;
        }    
    }
}