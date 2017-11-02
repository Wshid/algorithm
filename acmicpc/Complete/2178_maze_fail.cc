#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int maze[100][100];
int mark[100][100];
int m_search(int, int);
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool b_end=false;
int ret=0;
int result=0;
int N,M;

int main()
{
    cin>>N>>M;
    char input;
    char change[2];
    change[1]='\0';
    memset(maze,-1,sizeof(int)*100*100);
    memset(mark,-1,sizeof(int)*100*100);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++) // 1,1부터 시작하기!
        {
            cin>>input;
            change[0]=input;
            maze[i][j]=atoi(change);
        }

    m_search(1,1);
    cout<<result<<endl;

    return 0;
}


int m_search(int x,int y)
{
    
    if((x==N) && (y==M))
    {
      
        b_end=true;
        result=ret;
        //cout<<"ret="<<ret<<endl;
        return ret;
    }
    ret+=1;
    mark[x][y]=1;
   
   for(int i=0;i<4;i++)
   {
         cout<<"x="<<x<<"\t"<<"y="<<y<<"\tret="<<ret<<endl;
       if((mark[x+mv[i][0]][y+mv[i][1]]==1) || maze[x+mv[i][0]][y+mv[i][1]]!=1)
            continue;
       ret=min(ret,m_search(x+mv[i][0],y+mv[i][1]));
   }
}