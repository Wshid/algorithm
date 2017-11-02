#include<iostream>
#include<string.h>

using namespace std;

int input[101];
int cache[2][10001];
int n,k;

int main(){
    memset(cache, 0, sizeof(cache));
    
    cin>>n>>k;
    
    for(int i=1;i<=n;i++)
        cin>>input[i];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j==input[i])
                cache[i%2][j]=1;
            else if(j>input[i])
                cache[i%2][j]=cache[i%2][j-input[i]];
            else
                cache[i%2][j]=0;
            
            cache[i%2][j]+=cache[(i+1)%2][j];
        }
    }
    
    cout<<cache[n%2][k]<<endl;
}