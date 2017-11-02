#include<iostream>
#include<cstring>

#define MAX_N 101

using namespace std;

unsigned long long cache[MAX_N][MAX_N];
int N;
int board[MAX_N][MAX_N];

unsigned long long jump2(int y, int x);

bool is_inboard(int y, int x);

int main(){
    memset(cache, -1, sizeof(cache)); // 캐시배열 초기화
    memset(board, -1, sizeof(board)); // 보드배열 초기화
    
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }
    
    cout<<jump2(1,1)<<endl;

    return 0;
}

unsigned long long jump2(int y, int x){ // 무조건 다음 스텝에 있는 것을 참조하도록 변경
    unsigned long long &ret=cache[y][x];
    if(ret!=-1) return ret;
    
    int step=board[y][x];
    ret=0;
    
    if(y==N && x==N && step==0){ // 최종적으로 도달 했다면
        return ret=1;
    }
    
    if(step==0) return ret=0;
    
    /* 직선거리만 포함 */
    if(is_inboard(y+step, x)) ret+=jump2(y+step, x);
    if(is_inboard(y, x+step)) ret+=jump2(y,x+step);
    
    return ret;
    
}

bool is_inboard(int y, int x){
    if(1<=y && y<=N && 1<=x && x<=N) return true;
    else return false;
}