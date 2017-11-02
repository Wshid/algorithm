#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

vector<vector<int> > adj;

class compare{
    public:
        bool operator()(pair<int, int>a, pair<int, int>b){  // bool이라는걸 안써서 에러난듯
            return a.second>b.second; // 최소힙 관련
        }
};

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare > pq;
    
    pq.push(make_pair(3,3));
    pq.push(make_pair(2,4));
    
    for(int i=0; pq.size(); i++){
        cout<<pq.top().first<<endl;
        pq.pop();
    }
    
    return 0;
}