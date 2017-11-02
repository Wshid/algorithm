#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#define MAX_N 100001
#define LOW_BOUND -1001
using namespace std;

int n;
int input[MAX_N];
int cache[MAX_N];
// cache[][0] : 실제 리턴이 될 값
// cache[][1] : 해당 수까지 모두 더한 값

int psum(int idx, int term);

int main(){
    //memset(cache, LOW_BOUND, sizeof(cache));
    for(int i=0;i<=MAX_N;i++) cache[i]=LOW_BOUND;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>input[i];
    }
    
    //for(int i=1;i<=n;i++)
      //  cout<<input[i]<<"\t";
    
    if(n==1){
        cout<<input[1]<<endl; 
    }else{
        psum(1, 0);
        cout<<cache[n]<<endl;
    }
    return 0;
    
}

int psum(int idx, int term){ // term으로 중간자를 다 계산하도록 한다.
    int& ret=cache[idx];
    if(ret!=LOW_BOUND) return ret;
    // n...1로 가는 top - down 형식이 될 듯
    ret=cache[idx-1];
    
    if(idx==n){
        if(input[n]+term>ret) ret=input[n]+term;
        return ret;
    }
    
    if(term+input[idx]>=ret){
        ret=term+input[idx];
    }
    
    if(input[idx]<0 && abs(input[idx])>abs(term)){
        psum(idx+1, 0);
    }else{
        psum(idx+1, term+input[idx]);
    }
    
    return ret;
    
    /*
    int& linear=cache[idx][1];
    
    if(input[idx]>=0){
        ret=input[idx]+psum(idx-1);
        linear=
    }else{
        if(abs(input[idx]) > abs(ret)){
            ret=psum(idx-1);
            linear=0;
        }
    }*/
    
    
}