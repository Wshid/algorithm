#include<iostream>

using namespace std;
char str[1000001];

int main(){
    
    int count=0;
    cin.getline(str, sizeof(str));
    for(int i=0;i<sizeof(str);i++){

        if(str[i]!=' ' && (str[i+1]==' ' || str[i+1]==0))
            count++;
        
        if(str[i]==0)
            break;
    }
    cout<<count-1<<endl;
}