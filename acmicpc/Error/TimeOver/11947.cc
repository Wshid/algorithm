//시간초과 난다 ㅠㅠㅠㅠ 다른 방법 생각해보기
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int T, ret;
    vector<int> v;
    string temp;
    int i_temp, max;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>temp;
        i_temp=stoi(temp);
        max=0;
        for(int j=1;j<=i_temp;j++){
            ret=j*(pow(10,temp.length())-1-j);
            if(ret>max){
                max=ret;
            }
        }
        v.push_back(max);
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}