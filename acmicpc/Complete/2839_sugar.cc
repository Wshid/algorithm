#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int five, cur;
    
    if(n%5==0){
        cout<<n/5<<endl;
    }else{
        for(int i=n/5; i>0; i--){
            cur=n-(5*i);
            if(cur%3==0){
                cout<<i+(cur/3)<<endl;
                return 0;
            }
        }
        if(n%3==0){
            cout<<n/3<<endl;    
        }else{
            cout<<-1<<endl;
        }
        
    }
    return 0;
}

