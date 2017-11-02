#include<iostream>

using namespace std;

int main()
{
    int count=0;
    int white_board[8][8]={0};
    char board[8][8]={0};
    
    for(int i=0;i<8;i++)
    {
        for(int j=1;j<=4;j++){
            if(i%2==0)
                white_board[i][2*j-2]=1;
            else
                white_board[i][2*j-1]=1;
        }
    }
    
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin>>board[i][j];

    
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if((white_board[i][j]==1) && (board[i][j]=='F'))
                count++;

    cout<<count<<endl;
    
}