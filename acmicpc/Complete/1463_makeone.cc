// c9에서만 안돌아감. acmicpc.net에서는 정상제출됨

#include<iostream>
#include<cstring>

#define MAX_N 1000001

using namespace std;

int n;
int cache2[MAX_N];

int makeone2(int num);

int main(){

    memset(cache2, -1, sizeof(cache2));
    cin>>n;
    
    cout<<makeone2(n)<<endl;
    return 0;
}

int makeone2(int num){
    int &ret=cache2[num];
    if(ret!=-1) return ret;
    
    if(num==1) return ret=0;
    
    ret=makeone2(num-1)+1;
    if(num%3==0){
        ret=min(ret, makeone2(num/3)+1);
    }
    
    if(num%2==0){
        ret=min(ret, makeone2(num/2)+1);
    }
    
    return ret;
    
}