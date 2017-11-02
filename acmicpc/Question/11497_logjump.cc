/* 틀렸습니다.
 * 로직을 홀수 순서를 일련적으로 추가 하고
 * 짝수 순인것을 역순으로 정렬
 * 근데 틀림
 * 아오
 * 정규분포 형태로 구현해야한다고 함
 */
#include<iostream>
#include<vector>
#include<algorithm>
#define NSIZE_MAX 10001
#define NUM_MAX -1

using namespace std;

int T,N;
int L[NSIZE_MAX];
int maximum;
vector<int> R;// 리턴배열
vector<int> rev; // 역순환 배열
vector<int> ret_list;

int log_jump();
void init(int size);


int main(){
    
    cin>>T;
    for(int t=0;t<T;t++){
        init(N); // 이전 배열 초기화
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>L[i];
        }
        log_jump();
        ret_list.push_back(maximum);
    }
    
    for(int i=0;i<ret_list.size();i++)
        cout<<ret_list[i]<<endl;
    
    
}

int log_jump(){
    sort(L,L+N);
    for(int i=1;i<=N;i++){
        if(i%2) R.push_back(L[i]);
        else rev.push_back(L[i]);
    }
    
    for(vector<int>::reverse_iterator riter(rev.rbegin());riter!=rev.rend(); riter++){ // 역순환
        R.push_back(*riter);
    }
    
    for(int i=1;i<R.size();i++){
        if(maximum<(R[i]-R[i-1])) maximum=R[i]-R[i-1];
    }
    
    return maximum;
}

void init(int size){
    maximum=NUM_MAX;
    for(int i=0;i<size;i++){
        L[i]=-1;
    }
    R.clear();
    rev.clear();
}