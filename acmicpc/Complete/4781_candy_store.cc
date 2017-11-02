#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 5001
#define MAX_CAL 10001
using namespace std;

int n, m;
int cap;
float prev_m, prev_cap;
int in[MAX_N][2], cache[MAX_CAL];

int candy(int idx);

int main(){
    
    while(1){
        memset(in, -1, sizeof(in));
        memset(cache, -1, sizeof(cache));
        cin>>n>>prev_cap;
        //cout<<prev_cap<<endl;
        cap=(int)(prev_cap*100);
        //cout<<cap<<endl;
        if(n==0 && cap==0) break; // 입력 체크로 while문 종료
        for(int i=1;i<=n;i++){
            cin>>in[i][0]>>prev_m;
            m=(int)(prev_m*100);
            in[i][1]=m;
        }
        //cout<<"cap : "<<cap<<endl;
        cout<<candy(cap)<<endl;
        //for(int i=1;i<=n;i++) cout<<cache[i]<<endl;
        
    }
    
    
    return 0;
}

int candy(int idx){ // idx=cost가 되는것. 해당 금액에서 가능한 정도만큼 리턴
    
    int& ret=cache[idx];
    if(ret!=-1) return ret;
    
    ret=0;
    for(int i=1;i<=n;i++){// 현재것을 넣었을때와 안했을때 // 뺐다는 것은 넣어다는 것
        int inc=idx-in[i][1]; // 현재것을 포함 시켰을때
        if(inc>=0){
            ret=max(ret, candy(inc)+in[i][0]); // 현재 포함
            //ret=max(ret, candy()) // 현재 제외
        }
    }
    return ret;
}