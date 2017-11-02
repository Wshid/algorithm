// 출력도 제대로 되는 듯 한데.. 도대체 뭐가 틀린지 알수가 없다..

#include<iostream>
#include<string.h>

using namespace std;

int cache[40][2];
int T; //test case;

int countzero(int);
int countone(int);

int main()
{
    cin>>T;
    int N[T];
    for(int i=0;i<T;i++)
        cin>>N[i];
    for(int i=0;i<T;i++)
    {
        memset(cache,-1,sizeof(int)*40*2); // to memoization
        cout<<countzero(N[i])<<" "<<countone(N[i])<<endl;
    }
    

    return 0;
}

int countzero(int n)
{

    int& ret=cache[n][0];
    if(ret!=-1) return ret;
  //  cout<<"ret : "<<ret<<endl;
    //base case
    ret=0;
    if(n==0){
        ret++; return ret;
    }else if(n==1){
        return ret;
    }else{
        return ret=countzero(n-1)+countzero(n-2);
    }
}

int countone(int n)
{

    int& ret=cache[n][1];
    if(ret!=-1) return ret;
  //  cout<<"ret : "<<ret<<endl;
    //base case
    ret=0;
    if(n==0){
        return ret;
    }else if(n==1){
        ret++; return ret;
    }else{
        return ret=countone(n-1)+countone(n-2);
    }
}