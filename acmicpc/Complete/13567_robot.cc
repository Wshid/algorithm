#include<iostream>
#include<vector>
#include<string>

using namespace std;

int M,n; // 각각 길이와 노드를 의미함

int main()
{
    string comm[2]={"TURN", "MOVE"};
    string input;
    int semi;
    int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
    int cur[2]={0,0};
    int index=0;
    cin>>M>>n;
    for(int i=0;i<n;i++){
        string com;
        cin>>input;
        if(comm[0].compare(input)==0) com=comm[0];
        else if(comm[1].compare(input)==0) com=comm[1];
        else{
            cout<<"INVALID"<<endl;
            exit(1);
        }
        cin>>semi;
        
        if(com.compare(comm[0])==0){
            if(semi) index=(index+3)%4;
            else index=(index+1)%4;
        }else if(com.compare(comm[1])==0){
            cur[0]+=dir[index][0]*semi;
            cur[1]+=dir[index][1]*semi;
        }else{
            cout<<"INVALID"<<endl;
            exit(-1);
        }
        if((cur[0]<0) || (cur[0]>M) || (cur[1]<0) || (cur[1]>M)){
            cout<<-1<<endl;
            exit(0);
        }
        
    }
    
    cout<<cur[0]<<" "<<cur[1]<<endl;
    return 0;
}