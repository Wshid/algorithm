#include<iostream>
#include<vector>
#include<cstdio>
#define MAX_N 2001

using namespace std;


int S, E, N, M;
int inp[MAX_N];//, rinp[MAX_N]; // input 배열, 역순 input 배열
int cache[MAX_N][MAX_N]; // start-end의 배열이 palindrome 인가(1/0)

//bool is_pal(int start, int end); // start, end
int is_pal2(int start, int end); // memoization

int main(){
    int ret=0;
    
    ios_base::sync_with_stdio(false);
    
    for(int i=0;i<MAX_N;i++){ //캐시배열 초기화
        for(int j=0;j<MAX_N;j++){
            cache[i][j]=-1;
        }
    }
    
    //cin>>N;
    scanf("%d", &N);
    inp[0]=-1; // 임의의 값
    for(int i=1;i<=N;i++){
        scanf("%d", &inp[i]);
        //rinp[N+1-i]=inp[i]; // 역순으로 받는다.
    }
    
    //cin>>M;
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        //cin>>S>>E;
        scanf("%d %d", &S, &E);
        //if(is_pal(S, E)) cout<<1<<endl;
        ret=is_pal2(S, E);
        printf("%d\n", ret);
    }
    
    return 0;
}

int is_pal2(int start, int end){
    int& ret=cache[start][end];
    if(ret!=-1) return ret;
    
    if(start==end) return ret=1;
    if(start>end) return 1; // 이게 1이어야 맞음, 비교는 다 한것이므로,
    
    if(inp[start]==inp[end])
        return ret=is_pal2(start+1, end-1);
    else
        return ret=0;
}