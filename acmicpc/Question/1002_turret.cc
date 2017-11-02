#include<iostream>
#include<cmath>
#include<vector>
// 조건을 바꾸어야한다! 예외의 경우가 많음
using namespace std;

int main()
{
    int x[2], y[2],r[2];
    int dist, r_sum;
    int ret, T;
    vector<int> v;
    for(int i=0;i<T;i++){
        for(int j=0;j<2;i++)
            cin>>x[j]>>y[j]>>r[j];
        dist=sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2));
        r_sum=r[0]+r[1];
        
        if(dist>r_sum)
            v.push_back(0);
        else if(dist<r_sum)
            v.push_back(2);
        else if(dist==r_sum){
            if(x[0]==x[1] && y[0]==y[1])
                v.push_back(-1);
            else
                v.push_back(1);
        }else
            cout<<"oops!!"<<endl;
    }
    return 0;
}