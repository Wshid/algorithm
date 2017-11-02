// x,y형태로 구현한다
// y,x가 아닌

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int T; // Test Case
vector<int> L_list; // Size of Board

vector<pair<int,int> >s_point, e_point;
bool visited[300][300];
vector<pair<int ,int> > direc;
vector<int> ret;

class Node{
    public:
        int x, y, dist;
        Node(int _x, int _y, int _dist){
            x=_x;
            y=_y;
            dist=_dist;
        }
        
};

int find_node(pair<int, int> s_point, pair<int, int> e_point, int L);

int main()
{
    direc.push_back(make_pair(-2,-1));
    direc.push_back(make_pair(-2,1));
    direc.push_back(make_pair(-1,-2));
    direc.push_back(make_pair(-1,2));
    direc.push_back(make_pair(1,-2));
    direc.push_back(make_pair(1,2));
    direc.push_back(make_pair(2,-1));
    direc.push_back(make_pair(2,1));
    
    cin>>T;
    for(int i=0;i<T;i++){ // Test Cases
        int temp_x, temp_y, temp_L;
        cin>>temp_L; // Size
        L_list.push_back(temp_L);
        cin>>temp_x>>temp_y;
        s_point.push_back(make_pair(temp_x, temp_y));
        cin>>temp_x>>temp_y;
        e_point.push_back(make_pair(temp_x, temp_y));
    }
    /*
    for(int i=0; i<L_list[0];i++){
            for(int j=0;j<L_list[0];j++){
                cout<<visited[i][j]<<"\t";
            }
            cout<<endl;
    }*/
    
    for(int i=0;i<s_point.size();i++){
        //memset(visited, sizeof(visited), 0);
        for(int j=0;j<300;j++){
            for(int k=0;k<300;k++){
                visited[j][k]=0;
            }
        }
        int temp_ret=find_node(s_point[i], e_point[i], L_list[i]);
        ret.push_back(temp_ret);
    }
    /* 디버깅을 하면 visited가 이상함. 이전에 있던 visited가 제대로 초기화 되지 않음) */
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<endl;
    }
    return 0;
}

int find_node(pair<int, int> sp, pair<int, int> ep, int L)
{
    queue<Node> q;
    q.push(Node(sp.first, sp.second, 0));
    visited[sp.first][sp.second]=1;
    
    
    while(!q.empty()){
        //Node cur=q.top();
        Node cur=q.front();
        q.pop();
        
        if(cur.x==ep.first && cur.y==ep.second){
            return cur.dist;
        }
        
        for(int i=0;i<direc.size();i++){
            int next_x=cur.x+direc[i].first;
            int next_y=cur.y+direc[i].second;
            
            if(next_x>=0 && next_x<L && next_y>=0 && next_y<L){
                if(visited[next_x][next_y]==0){
                    visited[next_x][next_y]=1;
                    q.push(Node(next_x, next_y, cur.dist+1));
                }
            } else{
                continue;
            }
            
        }
        
        
    }
}