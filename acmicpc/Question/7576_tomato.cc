/* dfs를 이용하려 한다면,
 * visited[]배열이 무조건 필요하며 재귀적으로 구현하면 편하다
 * queue의 사용 없이 그냥 접근해도 될 듯함
*/

/* 다 못 익게 하는 것에 대해 -1로 정의하므로
 * 굳이 뭐 해줄 필요가 없다 그냥 for문 하나만 쓰면 될 듯
 * 문제는 익는 방향의 이동인데, 배열에서 이동하면 될 듯 단, 
 * 외부로는 못나가 도록 예외처리 하는 방식으로 이동할 수 있도록 한다
 */

#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

int M,N;
bool tom[1001][1001];
bool visited[1001][1001];
int cnt;
queue<pair<int, int> >root_list;

int mature(pair<int, int> root);

int main(){
    int ret=0;
    memset(visited, sizeof(visited), false);
    cin>>M>>N;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>tom[i][j];
            root_list.push(make_pair(tom[i][j]));
        }
    }
    
    for(int i=0;i<root_list.size();i++){
        root_list.top();
        root_list.pop();
        ret=max(ret ,mature(root_list[i]));
    }
    
}

int mature(pair<int, int> node){ // rootX, rootY
    pair<int, int> dir[4]={make_pair(1,0), make_pair(0,1), make_pair(-1,0), make_pair(0,-1)};
    int ret=0;
    if(node.first<1 || node.first>M || node.second<1 || node.second>N)
        return 0;
    if(visited[node.first][node.second]) return 0;
    
    visited[node.first][node.second]=true;
    for(int i=0;i<4;i++){
        ret=max(ret, 1+mature(make_pair(node.first+dir[i].first, node.second+dir[i].second)));
    }
    return ret;
}