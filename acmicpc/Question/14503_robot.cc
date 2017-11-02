/*
 * 빈칸 : 0 / 벽 : 1 // 청소했을경우 : 2
 * 0 1 2 3 : 북, 동, 남, 서
 */

#include<iostream>
#include<vector>
#define MAX_MN 52

using namespace std;

int N,M;
int board[MAX_MN][MAX_MN];
int r,c,d;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; // 북, 동, 남, 서

int move(int r, int c, int d);

int main(){
    
    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j]; // 인풋 입력받기
        }
    }
    
    for(int i=0;i<=N+1; i++){ // 경계 벽 세우기
        board[i][0]=1;
        board[i][M+1]=1;        
        
    }
    for(int i=0;i<=M+1;i++){
        board[0][i]=1;
        board[N+1][i]=1;
    }
    
    cout<<move(r,c,d)<<endl;
    
    return 0;
}

int move(int r, int c, int d){

    int ret=0;

    while(1){ // 1번 조건 담당 while문
        
        ret++; 
        if(board[r][c]==0) board[r][c]=2; // 청소함
        
        while(1){ // 2번 조건 부분, break시 1번으로, continue시 2번으로
            cout<<r<<","<<c<<endl; // 6,3 6,4에서 루프돈다.
            int check=((d-1)+4)%4; // 현재의 왼쪽 방향 구하기
            int nr=r+dir[check][0], nc=c+dir[check][1];
            
            if(board[nr][nc]==0){ // 1번 조건, 왼쪽 방향이 0일때
                d=check; // 다음 방향
                r=nr;// 위치 이동
                c=nc;
                break; // 1번 조건으로 이동
            } else { // ### 로직 꼬여있음 2번 조건 분기 제대로 할 것
                bool able=false;
                for(int i=0;i<4;i++){
                    // 왼쪽 먼저 이동하도록 해야함
                    int lc=((d-i)+4)%4;
                    if(!board[r+dir[lc][0]][c+dir[lc][1]]){ // 4방향 비교시, 0이 있다면
                        // 0이라면?
                        d=lc;
                        able=true;
                        break; // ### 여기 처리가 조금 이상함
                    }
                }
                if(able) continue; //2번으로
                else{
                    //3번과 4번 비교
                    cout<<"AA"<<endl;
                    //d+2 // 뒤방향을 보게됨
                    if(board[r+dir[(d+2)%4][0]][c+dir[(d+2)%4][1]]==2){ // 뒤가 청소한 부위라면, 뒤로 이동 가능함
                        r+=dir[(d+2)%4][0];
                        c+=dir[(d+2)%4][1];
                        continue; // 2번으로 이동
                    }else{
                        return ret; // 못감
                    }    
                }
                
            }
        }
    }
    
}