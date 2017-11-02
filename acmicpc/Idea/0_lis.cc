#include<iostream>
#include<vector>

using namespace std;

int n;
int cache[100], S[100];
int cache3[101];
int main(){
    
}

int lis2(int start){ //O(n^2)
    int& ret=cache[start];
    
    if(ret!=-1) return ret;
    
    ret=1;
    
    for(int next=start+1;next<n;next++){
        if(S[start]<S[next])
            ret=max(ret, lis2(next)+1);
    }
    return ret;
}


int lis3(int start){
    int& ret=cache[start+1];
    if(ret!=-1) return ret;
    
    ret=1;
    for(int next=start+1;next<n;next++){
        if(start==-1 || S[start]<S[next])
            ret=max(ret, lis3(next)+1);
    }
    return ret;
}

텅 빈 수열에 숫자를 추가하며 진행하기
증가 수열의 마지막 수가 무엇인지 확인
C[i] 지금까지 만든 부분 배열이 갖는 길이 i인 증가 부분 수열ㅈ중
최소의 마지막 값    

C[]내에서 이분검색이 가능하게 됨
길이에 대한 배열이 되겠네..
