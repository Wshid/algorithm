#include<iostream>
#include<string.h>

using namespace std;

double input[1000], m=0.00, sum=0.00;
int n=0;


int main(){
    
    memset(input, 0, sizeof(input));
    
    cin>>n; // n<=1000
    for(int i=0;i<n;i++){
        cin>>input[i];
        if(m<input[i])
            m=input[i]; // m를 같이 구해낸다.
    }
    
    for(int i=0;i<n;i++){
        sum+=(input[i]/m)*100;
    }
    
    printf("%.2f", sum/n);
    
    return 0;
}