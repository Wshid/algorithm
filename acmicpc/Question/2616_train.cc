#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 50001

using namespace std;
int N, input[MAX_N], CNT;
int cache[MAX_N][2];


void prev_sum();
//int train(int idx, int step, int left);
int train2(int idx, int step, int left, int choice);

int main(){
    cin>>N;
    memset(cache, -1, sizeof(cache));
    for(int i=1;i<=N;i++){
        cin>>input[i];
    }
    cin>>CNT;
    
    //prev_sum();
    /*
    train(1, CNT, 3);
    cout<<cache[1]<<endl;
    for(int i=1;i<=N;i++)
        cout<<cache[i]<<"\t";*/
        
    train2(1, CNT, 3, 1);
    train2(1, CNT, 3, 0);
    
    for(int i=1;i<=N;i++)
        cout<<cache[i][0]<<"\t"<<cache[i][1]<<endl;
    cout<<max(cache[1][0], cache[1][1])<<endl;
    return 0;
}


/* 숫자가 1일때 제대로 먹지 않음 */
/*
int train(int idx, int step, int left){
    int& ret=cache[idx];
    if(ret!=-1) return ret;
    if(left==0) return 0;
    if(idx==N) return 0;
    
    if(idx+step-1<=N && idx+step*(left-1)<=N){ // 조건을 하나 더 붙여주어야 함. 앞으로 가능성이 있는가에 대해 
        int sum=0;    
        for(int i=0;i<step; i++)
            sum+=input[idx+i];
        return ret=max(sum+train(idx+step, step, left-1), train(idx+1, step, left));
    }else return ret=0;
    
}
*/
/* cache[0] : 선택하지 않았을 때, cache[1] : 선택했을때로 구분 */

int train2(int idx, int step, int left, int choice){
    int& ret=cache[idx][choice];
    if(ret!=-1) return ret;
    if(left==0) return 0;
    if(idx-1 +step>N) return 0;
    
    // 선택시
    if(idx-1+step<=N){
        if(choice){
            int sum=0;
            for(int i=0;i<step;i++) sum+=input[idx+i];
            return ret=max(train2(idx+step, step, left-1, 0), train2(idx+step, step, left-1, 1))+sum;
        }else{ // 미 선택시
            return ret=max(train2(idx+1, step, left, 0), train2(idx+1, step, left, 1));
        }        
    }else return ret=0;

}