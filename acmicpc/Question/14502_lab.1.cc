// 0은 빈칸, 1은 벽, 2는 바이러스
/*
 * 생각해보면, 판마다 새로 cache배열을 제작해야함
 * 그를 관리하는 max 변수가 있는 것이고, 이를 처리를 해야할 것
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAX_MN 9
#define INIT_WALL 3
#define DIR_SIZE 4

using namespace std;

int N,M;
int ret_max; // 최종적으로 반환할 값
int cache[MAX_MN][MAX_MN];
int board[MAX_MN][MAX_MN];
int input[MAX_MN][MAX_MN];
bool visit[MAX_MN][MAX_MN];
bool raw_visit[MAX_MN][MAX_MN];
queue<pair<int, int> > q; // 다음 시작할 지점을 저장하고 있는 큐

int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};

int lab(int y, int x, int wall);
bool check_all();

int main()
{
    int tmp;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>tmp;
            if(!(tmp==0)) raw_visit[i][j]=1;
            input[i][j]=tmp;
            if(tmp==2) q.push(make_pair(i, j));
        }
    }
    
    
    while(!q.empty()){
        //copy(input, input+(9*9+1), board); // copy 함수에서 에러 발생
        //memcopy(board, input, sizeof(input));
        //copy(raw_visit, raw_visit+(9*9+1), visit);
        //memcopy(visit, raw_visit, sizeof(raw_visit));
        //pair<int, int> next=q.front(); // 이게 왜 안되지..?
        
        int next_y=q.front().first, next_x=q.front().second;
        
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<MAX_MN; i++){ // 배열 원소 초기화
            for(int j=0;j<MAX_MN;j++){
                board[i][j]=input[i][j];
                visit[i][j]=raw_visit[i][j];
            }
        }
        
        q.pop();
        visit[next_y][next_x]=1;
        
        ret_max=max(ret_max, lab(next_y, next_x, INIT_WALL));
        cout<<"MID : "<<ret_max<<endl;
    }
    
    cout<<ret_max<<endl;
    
    
    return 0;
}

int lab(int y, int x, int wall){ // 현재의 부분에 벽을 세우든.안세우든 했을 때 앞으로 얻을 수 있는 최대갑의 수
    cout<<"(y, x) : "<<y<<","<<x<<endl;
    int& ret=cache[y][x];
    if(ret!=-1) return ret;
    
    if(check_all()){
        return ret=1;
    }
    
    ret=0;
    
    // 이게 애매한게 여기 부분을 정해야 할 듯함
    //0인부분은 2나 1로 바뀌어 나가야 함
    if(board[y][x]==2){ // 현재의 점이 2라면?, 2이어야지 다음 점에 대해 선택할 권리가 생김
        for(int i=0;i<DIR_SIZE;i++){
            int ny=y+dir[i][0], nx=x+dir[i][1];
            cout<<"(ny, nx) : "<<ny<<","<<nx<<endl;
            if(ny>0 && ny<=N && nx>0 && nx<=M){
                if(visit[ny][nx]==0 && board[ny][nx]==0){ // 당연히 안됨, board값을 전환하고 visit값이 안변하기 때문에 어쨌든 그리됨
                    cout<<"IN"<<endl;
                    visit[ny][nx]=1;
                    //board[ny][nx]=2;
                    if(wall>0){ // 벽을 세울 수 있음
                        board[ny][nx]=1;
                        ret=lab(ny, nx, wall-1); // 카운트를 증가시는 시점 조차 애매함, 벽을 세우게 되면 그건 아니겠지 채우는게
                    }
                    board[ny][nx]=2; // 바이러스를 확장시키기
                    ret=max(ret, lab(ny,nx, wall)+1);
                    visit[ny][nx]=0;
                }
            }
        }
    }
    
    return ret;
    
    
}

bool check_all(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(!visit[i][j]){
                return false;
            }
        }
    }
    return true;
}