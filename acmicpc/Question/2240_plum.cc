#include<iostream>
#include<cstring>
#define MAX_N 1001

using namespace std;

int T,W;
int input[MAX_N];
int cache[MAX_N][2]; // 움직인다, 움직이지 않는다.

int plum(int idx, int loc, int step);

int main(){
    memset(cache, -1, sizeof(cache));
    input[0]=1;
    cin>>T>>W;
    
    for(int i=1;i<=T;i++)
        cin>>input[i];
    
    cout<<plum(0,0,W)<<endl;
    
    return 0;
}

int plum(int idx, int loc, int step){ // 현재 인덱스, 위치, 남은 이동 수
    int& ret=cache[idx][loc]; // 1을 선택할지 2를 선택할지의 문제가 아닌 듯한데
    if(ret!=-1) return ret;
    
    if(idx+1==T){
        if(input[idx]==input[idx+1]) return ret=1;
        else return ret=0;
    }
    
    if(step==0){ // 움직였다면 그대로, 움직이지 않았다면 뭐..
        if(input[idx]==input[idx+1]) return ret=plum(idx+1, loc, 0)+1;
        else return ret=plum(idx+1, loc, 0);
    }
    
    ret=0;

    if(input[idx]==input[idx+1]){ // loc은 0과 1이 있다고 가정, 0은 2 1은 1
        return ret=max(plum(idx+1,loc,step)+1, plum(idx+1,(loc+1)%2,step-1));// 일치할 경우
    }else{
        return ret=max(plum(idx+1,(loc+1)%2,step-1)+1, plum(idx+1,loc,step));// 불일치할 경우
    }
    
    return ret;
    
}