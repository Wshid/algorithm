#include<iostream>
#define MAX_MN 20

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

#define UP 0
#define FRONT 1
#define BACK 2
#define BOT 3
#define LEFT 4
#define RIGHT 5

using namespace std;

int x, y, K, N, M; // N : 세로, M : 가로
int board[MAX_MN][MAX_MN];
int dice[6];
int temp[6];
/*
 * 0 : 위
 * 1 : 정면
 * 2 : 뒷면
 * 3 : 아래
 * 4 : 왼쪽
 * 5 : 오른쪽
*/

void roll(int y, int x, int dir);
bool is_zero(int y, int x);
bool is_in(int y, int x);

int main(){
    
    int dir;
    
    cin>>N>>M>>y>>x>>K;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    
    for(int i=0;i<K;i++){
        cin>>dir;
        //cout<<"i : "<<i<<endl;
        //cout<<"y : "<<y<<"\t x : "<<x<<endl;
        roll(y, x, dir);
    }
    return 0;
}

bool is_zero(int y, int x){ // 0일 경우 return false
    if(board[y][x]) return true;
    else return false;
}

bool is_in(int y, int x){ // 보드 내부에 있는지 판단
    if(y>=0 && y<N && x>=0 && x<M) return true;
    else return false;
}

void roll(int y_raw, int x_raw, int dir){ //dir(방향)을 받아 처리

    int ny=-1, nx=-1; // next_y, next_x;
    for(int i=0;i<6;i++) // 이동 전 복사
        temp[i]=dice[i];
        
    switch(dir){
        case EAST:
            if(is_in(y_raw, x_raw+1)){
                ny=y_raw;
                nx=x_raw+1;
                dice[UP]=temp[LEFT];
                dice[RIGHT]=temp[UP];
                dice[BOT]=temp[RIGHT];
                dice[LEFT]=temp[BOT];
                dice[FRONT]=temp[FRONT]; // 의미 없음
                dice[BACK]=temp[BACK]; // 의미 없음
            }
            break;
        case WEST:
            if(is_in(y_raw, x_raw-1)){
                ny=y_raw;
                nx=x_raw-1;
                
                dice[UP]=temp[RIGHT];
                dice[RIGHT]=temp[BOT];
                dice[BOT]=temp[LEFT];
                dice[LEFT]=temp[UP];
                dice[FRONT]=temp[FRONT]; // 의미 없음
                dice[BACK]=temp[BACK]; // 의미 없음                
            }
            break;
        case NORTH:
            if(is_in(y_raw-1, x_raw)){
                ny=y_raw-1;
                nx=x_raw;
                
                dice[UP]=temp[BACK];
                dice[RIGHT]=temp[RIGHT]; // 의미 없음
                dice[BOT]=temp[FRONT];
                dice[LEFT]=temp[LEFT]; // 의미 없음
                dice[FRONT]=temp[UP]; 
                dice[BACK]=temp[BOT]; 
            }
            break;
        case SOUTH:
            if(is_in(y_raw+1, x_raw)){
                ny=y_raw+1;
                nx=x_raw;
                
                dice[UP]=temp[FRONT];
                dice[RIGHT]=temp[RIGHT]; // 의미 없음
                dice[BOT]=temp[BACK];
                dice[LEFT]=temp[LEFT]; // 의미 없음
                dice[FRONT]=temp[BOT]; 
                dice[BACK]=temp[UP]; 
            }
            break;
        default:
            cout<<"ERROR"<<endl;
            return;
    }
    
    if(ny==-1 || nx==-1){ // 보드 판 안에 들어가지 못했다는 의미
        return; // 함수 종결
    }
    
    y=ny;
    x=nx;
    
    if(board[ny][nx]){ // 0이 아닌 값일때
        dice[BOT]=board[ny][nx]; // 주사위로 복사
        board[ny][nx]=0; // 보드 자리 0
        
    }else{ // 0일때 // 바닥면 복사
        board[ny][nx]=dice[BOT];
    }
    
    cout<<dice[0]<<endl;
    return;
}