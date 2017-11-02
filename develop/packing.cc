#include<iostream>
#include<string>
#include<vector>

using namespace std;

int pack(int, int);
void reconstruct(int,int, vector<string>&);

template<class T> // 세미콜론이 필요 없음, template<typename T>와 같은의미, 어떤것을 쓰던지 상관 없음
void print_vector(vector<T>&);

int n, W; // Count of Items, Total Weight
int volume[100], need[100];
int cache[1001][100]; // cache에서 weight에 관해 index가 0일때 쓸모가 없음, 1부터 의미가 있기때문에 1000까지의 집합에서도 1을 추가하여 사용
vector<string> ret_vector;
string name[100];

int main(int argc,char** argv)
{
    cout<<"start"<<endl;

    cin>>n;
    cin>>W;
    
    for(int i=0; i<=W;i++) // 해당 Weight에서의 값까지 요구하므로 W는 포함해야함
        for(int j=0;j<n;j++) // n은 단순 갯수를 의미하므로 굳이 수까지 포함시킬 이유는 없음
            cache[i][j]=-1;
            
    
    for(int i=0; i<n;i++)
        cin>>name[i]>>volume[i]>>need[i]; // 차례로 물건 이름, 부피, 절박도(우선순위)를 입력받음
        
    cout<<pack(W,0)<<" "; // pack 함수 돌리기
    reconstruct(W,0,ret_vector); // 역추적으로 무엇 선택했는지 확인
    cout<<ret_vector.size()<<endl; // vector 내부 원소 몇개?
    print_vector(ret_vector); // vector 내부 값 출력
    
     /*for(int i=0; i<=W;i++){ // cache내부 원소값 확인
        for(int j=0;j<n;j++)
            cout<<cache[i][j]<<"\t";
        cout<<endl;
     }*/
    
    return 0;
}



int pack(int capacity, int item)
{
    if(item==n) return 0;
    int& ret=cache[capacity][item]; // 해당 용량으로 부터 item 이후의 최적합(capacity는 높을 수록, item은 낮을수록 수가 커질듯)
    if(ret!=-1) return ret;
    ret=pack(capacity,item+1);
    
    if(capacity>=volume[item])
        ret=max(ret,pack(capacity-volume[item],item+1)+need[item]);
    return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) // 역추적과정에서 이루어짐
{
    if(item==n) return;
    
    if(pack(capacity, item)==pack(capacity,item+1)) // 만약 현재부터의 최적값과, 그 다음값과의 최적값이 같다면, 해당 item을 선택하지 않은 것
        reconstruct(capacity,item+1,picked); // 현재의 아이템을 지나치고 다음 호출
    else
    {
        picked.push_back(name[item]); // 출력할 배열 후미에 값을 추가
        reconstruct(capacity-volume[item],item+1,picked); // 아이템을 추가했으므로, 용량 감소, 아이템 다음 호출
    }
}

template<class T> 
void print_vector(vector<T>& v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    cout<<endl;
    return;
}