#include<iostream>
#include<cstring>

#define MAX_MN 501
#define MAX_H 10001

using namespace std;

int N, M;
int board[MAX_MN][MAX_MN];
int cache[MAX_MN][MAX_MN];
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};

int desc(int y, int x);
bool is_inboard(int y, int x);

int main()
{
    memset(board, -1, sizeof(board));
    memset(cache, -1, sizeof(cache));
    
    cin>>M>>N; // 세로가 M
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }
    
    cout<<desc(1,1)<<endl;
    
    return 0;
}


int desc(int y, int x){
    int& ret=cache[y][x];
    if(ret!=-1) return ret;
    
    if(y==M && x==N){
        return ret=1;
    }
    ret=0;
    
    for(int i=0;i<4;i++){
        int next_y=y+dir[i][0], next_x=x+dir[i][1];
        if(is_inboard(next_y, next_x)){ // 다음 점이 board 판 안에 존재하고
            if(board[next_y][next_x]<board[y][x]){ // 다음 점의 높이가 무조건 낮다면
                ret+=desc(next_y, next_x); // 이동
            }
        }
    }
    
    return ret;
}

bool is_inboard(int y, int x){
    if(1<=y && y<=M && 1<=x && x<=N) return true;
    else return false;
}