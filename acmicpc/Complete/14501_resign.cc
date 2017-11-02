#include<iostream>
#include<cstring>
#include<vector>
#define MAX_N 16

using namespace std;

int cache[MAX_N][2]; // 포함, 포함하지 않음
int T[MAX_N]; // 기간
int P[MAX_N]; // 보상
int N;

//int resign(int idx, int include); // 현재 인덱스와 포함 여부
int resign2(int idx, int include);

int main(){
    memset(cache, -1, sizeof(cache));
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>T[i]>>P[i];
    
    T[0]=1;
    P[0]=0;
    //cout<<resign(0,1)<<endl; // 시작 문자, 0번째를 포함하여 시작한다.
    cout<<resign2(0,1)<<endl; // 시작 문자, 0번째를 포함하여 시작한다.
    // 물론 0번째에는 0으로 초기화 되어 있어야 함
    /*
    for(int i=0;i<=N+1;i++){ // 테스트 코드
        cout<<i<<"\t"<<cache[i][0]<<"\t"<<cache[i][1]<<endl;
    }*/
    
    return 0;
}
/*
int resign(int idx,int include){ // (idx, include) // T가 하루 P가 비용
    int& ret=cache[idx][include];
    if(idx==11) cout<<"!!!!!!!!"<<endl;
    if(ret!=-1) return ret;
    
    if(idx-1==N){ // idx가 N+1일때 끝내기로
        if(T[idx-1]==1) return ret=P[idx-1];
        else return ret=0;
    }
    // 1번째 예제 실행시 에러
    //cout<<idx<<","<<include<<endl;
    if(include){//include=1;
        if(idx+T[idx]-1<=N) // 여기 부분이 문제인듯
            if(T[idx]!=1)// T[idx]=1 이라면, idx그대로를 참조함 // 본인재귀가 된다는 의미
                return ret=max(resign(idx+T[idx], 0), resign(idx+T[idx], 1))+P[idx];
            else
                return ret=max(resign(idx+1, 0), resign(idx+1, 1))+P[idx];
        else return ret=0;
    }else{ // include=0; // 내꺼 포함안시킬꺼임
        if(idx+1<=N)
            return ret=max(resign(idx+1, 0), resign(idx+1, 1));
        else return ret=0;
    }
    
    
}*/


// 3,4예제 적용시 제대로 된 값이 출력되지 않음

int resign2(int idx,int include){ // (idx, include) // T가 하루 P가 비용
    int& ret=cache[idx][include];
    if(ret!=-1) return ret;
    //if(idx==N+1) cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;
    if(idx==N){
        if(T[idx]==1) return ret=P[idx];
        else return ret=0;
    }
    if(include){//include=1;
        if(idx+T[idx]-1==N){
            return ret=P[idx];
        }
        if(idx+T[idx]<=N) // 여기 부분이 문제인듯
            return ret=max(resign2(idx+T[idx], 0), resign2(idx+T[idx], 1))+P[idx];
        else return ret=0;
        
    }else{ // include=0; // 내꺼 포함안시킬꺼임
        if(idx+1<=N)
            return ret=max(resign2(idx+1, 0), resign2(idx+1, 1));
        else return ret=0;
    }
    
    
}