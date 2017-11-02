#include<iostream>
#include<cstring>
#define MAX_N 12

using namespace std;

int T;
int sum_list[MAX_N];
int sum(int n);

int main(){
    memset(sum_list, -1, sizeof(sum_list));
    sum_list[0]=0;
    cin>>T;
    int n;
    for(int i=0;i<T;i++){
        cin>>n;
        cout<<sum(n)+1<<endl;
    }
}

int sum(int n){
    int& ret=sum_list[n];
    if(ret!=-1) return ret;
    if(n==0) return 0;
    
    if(n>=3){
        ret+=(sum(n-3)+1);
    }
    
    if(n>=2){
        ret+=(sum(n-2)+1);
    }
    
    if(n>=1){
        ret+=(sum(n-1)+1);
    }
    
    return ret;
}