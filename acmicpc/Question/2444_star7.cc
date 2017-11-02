#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=2*n-1;i=i+2)
    {
       // cout<<"what"<<endl;

      //  for(int k=n-1;k>0;k--)
           // cout<<" ";
        cout.width(n-1);
        for(int j=0;j<i;j++)
            cout<<right<<"*";
            
        cout<<endl;
    }

        // 일단은 이렇게 되면.. 1,3,5,7,9 반복
}