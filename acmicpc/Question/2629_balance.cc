/* 
 * 테스트 케이스 종속 에러 // 해결
 * 런타임에러 발생 // 확인해보기 // 해결?
 * 45%에서 틀렸습니다 발생 // abs해도 의미가 없음.. 뭐지
 */

#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

#define MAX_N 31 // 최대 추의 개수
#define MAX_T 7
#define MAX_C 15001

using namespace std;

int N, T; // 추의 개수, 검증할 추의 개수
int norm[MAX_N];
int input;
int cache[MAX_C];
bool visited[MAX_N];

int bal(int idx);

int main(){
    //memset(cache, -1, sizeof(cache)); // 순서에 따라 빼는 경우는 생각을 안할 수 있다. 따라서 abs연산자를 사용해야한다.
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>norm[i];
    }
    
    cin>>T;
    for(int i=0;i<T;i++){
        memset(cache, -1, sizeof(cache));
        memset(visited, false, sizeof(visited));
        /*for(int j=0;j<MAX_N;j++){
            visited[j]=0;
        }*/
        
        cin>>input;
        if((input>=MAX_C) || (input<=0)){
            cout<<"N"<<" ";
        }else{
            if(bal(input)==0){
                cout<<"Y"<<" ";
            }else{
                cout<<"N"<<" ";
            }            
        }

    }
    
    return 0;
}

int bal(int idx){
    int& ret=cache[idx];
    if(ret!=-1) return ret;
    if(idx==0) return ret=0;
    
    for(int i=1;i<=N;i++){ // visited : cur Node , 사이즈 비교 : Next node
        if(visited[i]) continue;
        int next[2]={abs(idx-norm[i]), abs(idx+norm[i])};
        visited[i]=1;
        
        if(next[0]>=0){
            if(bal(next[0])==0) return ret=0;
        }
        
        if(next[1]<MAX_C){
            if(bal(next[1])==0) return ret=0;
        }
            
        //if(bal(next[2])==0) return ret=0;
        
        visited[i]=0;
    }
    
    return ret=-2;
}

// 넣지 않는 경우도 고려를 해야함. 이를 어떻게 측정하여 분기하는 것이 문제
