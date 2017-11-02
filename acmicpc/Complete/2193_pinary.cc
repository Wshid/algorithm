#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 91

using namespace std;

int N;
long long pinary(int num, bool pin);
long long cache[MAX_N][2]; // N자리 수로 만들수 있는 이친수의 수

// cache[10][1];
//101010101010
// cache[10][0];

// cache[5][1];

int main(){
    memset(cache, -1, sizeof(cache));
    cin>>N;
    cout<<pinary(N, 1)<<endl;
    
    return 0;
}

long long pinary(int num, bool pin){ // pin은 0과 1을 의미, num은 자리수
    long long& ret=cache[num][pin];
    if(ret!=-1) return ret; // 이미 계산이 되었다면 계산하지 않음
    
    if(num==1) return ret=1; // 1자리 수라면 1을 리턴(갯수가 1이 되는 것이므로)
    
    ret=0;
    if(pin) // 현재 선택한 핀이 1이라면
        ret+=pinary(num-1,0); // 다음은 무조건 0이되어야 한다.
    else // 현재 선택한 핀이 0이라면
        ret=ret+pinary(num-1,0)+pinary(num-1,1); // 다음은 1과, 0이 될 수 있다.
    
    return ret; // ret를 리턴한다.
}