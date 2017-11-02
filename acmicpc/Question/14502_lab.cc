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
//bool raw_visit[MAX_MN][MAX_MN];
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
            if(!tmp) input[i][j]=tmp;
            if(tmp==2) q.push(make_pair(y, x));
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int step=3;
            
            board[i][j]=1;
            
            while(!q.empty()){
                int ny=q.front().first, nx=q.front().second;
                ret_max=max(ret_max, lab(y, x, INIT_WALL));    
                
            }
            
            
        }
    }
    
    
    
    return 0;
}

int lab(int y, int x)//, int step){
    for(int i=0;i<4;i++){
        int ny=y+dir[i][0], nx=x+dir[i][1];
        
        if(ny>0 && ny<=N && nx>0 && nx<=M){
            
        }
    }
}

int wall(int y, int x, int step){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=1;jk<=3;i++){
                
            }
        }
    }
}