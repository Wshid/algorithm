/* FAIL 단순 연산 계산도 못하냐.. */
#include<iostream>
#include<queue>
//#include<algorithm>
#include<vector>
#include<functional> //priority queue 사용시 사용하기


using namespace std;

int N, cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue <int, vector<int>, less<int> > lq; // 가장 큰 값부터 뽑힘
    priority_queue <int, vector<int>, greater<int> > rq; // 가장 작은값 부터 뽑힘
    
    int in, temp;
    cin>>N;
    /* min q -> max_q */
    for(int i=0;i<N;i++){
        cin>>in;
        /* left_q.top() right_q.top() in을 비교를 해야함 */
        
        if(lq.size()==0){
            lq.push(in);
        }
        else{
            if(rq.size()==0){
                if(in>=lq.top()){
                    rq.push(in);
                }else{
                    temp=lq.top();
                    lq.pop();
                    rq.push(temp);
                    lq.push(in);
                }
            }else{
                if(rq.top()<=in){
                    if(lq.size()>=rq.size()){
                        rq.push(in);
                    }else{
                        temp=rq.top();
                        rq.pop();
                        lq.push(temp);
                        rq.push(in);
                    }
                    
                }else{ // rq.top()>=in
                    if(lq.size()>=rq.size()){
                        rq.push(in);
                    }else{ // lq.size!=rq.size
                        temp=lq.top();
                        lq.pop();
                        lq.push(in);
                        rq.push(temp);
                    }
                }                
            }


        }
        cout<<"lq.size() : "<<lq.size()<<"\t"<<lq.top()<<endl;
        cout<<"rq.size() : "<<rq.size()<<"\t"<<endl;
        cout<<lq.top()<<"\n";
        
    }
    
    
    return 0;
}