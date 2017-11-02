#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const int& i,const int& j){
    return i<j;
}

#define INF 10000

int n;
vector<int> p(51); // store index
vector<int> a(51); // origin
vector<int> b(51); // be sorted
vector<int> dup(51,0); // checked, is duplicated?

int psort()
{
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<n-i;j++){
            if(b[j]>b[j+1]){
                swap(b[j],b[j+1]);
            }
        }
    }
    for(int i=1;i<n;i++){
        if(b[i-1]==b[i]){
            dup[i]=dup[i-1]+1;
        }
        //cout<<"i-1 : "<<dup[i-1]<<"\t"<<"i : "<<dup[i]<<endl;
    }
}
int main(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    
    
    psort();
    
    for(int i=0;i<n;i++)
        cout<<b[i]<<"\t"<<dup[i]<<endl;
    
   // sort(b.begin(),b.begin()+n,compare);
 /* 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                p[i]=j;
                //cout<<"i = "<<a[i]<<"\tj = "<<b[j]<<endl;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<p[i]<<"\t";
   */     
   
   // 배열은 정렬이 되었고,
   // 이제 인덱스 값을 찾아가기만 하면 되는데,
   // 이제 찾을꺼 아냐 origin인 a의 값을 찾아가야함
   // b에서
   // 찾고나서 제거 해야하지 않음?
   // 그니까 일치하게 된다면 b[i]에서 제거
   // 그리고 dup[i]에서도 제거
   // 근데 그러면 인덱스상의 문제가 생길 수 있음
   // 일치하게 된다면, 그 값을 1000이상의 특수한 값으로 놓아버리면 되지 않을까?
   // dup[i]에서도 제거하지 않아도 됨
   // 하지만 합친 값이 실제 인덱스와 겹치는 경우가 생김
   // a에는 원래 인덱스, b에는 정렬된 인덱스, p는 정렬되도록 만드는 인덱스
   // 왜 이게 복잡하기 미쳤네
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(i!=j && a[i]==b[j]){
               p[i]=j+dup[j];
               b[j]=INF;
           }
       }
   }
   cout<<"====="<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<"\t"<<p[i]<<endl;
    }
    return 0;
}