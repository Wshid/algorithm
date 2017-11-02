#include<iostream>
#include<vector>

using namespace std;

vector<int> slice(const vector<int>& v, const int a, const int b){
    return vector<int>(v.begin()+a,v.begin()+b);
}

int main(void){
    
    vector<int> v(7);
    
    v[0]=27;
    v[1]=16;
    v[2]=9;
    v[3]=12;
    v[4]=54;
    v[5]=46;
    v[6]=72;
    
    vector<int> v2;
    v2=slice(v,1,3);
    
    
    for(int i=0;i<v2.size();i++)
        cout<<"v2["<<i<<"]="<<v2[i]<<endl;
    
    return 0;
}