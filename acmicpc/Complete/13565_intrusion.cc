#include<iostream>
#include<vector>
#include<cstring>

#define MAX 1001

using namespace std;


// dp로 푼다고 했을때,
// 해당 점으로부터 끝까지 갈 수 있다는 가능성이 있다면 true를 반환


int M,N; // M이 y에 해당, N이 x에 해당
int map[MAX][MAX];
//bool visited[MAX][MAX];
vector<pair<int, int> > direc;
//bool ret=false;
int cache[MAX][MAX];
// -1은 탐색해야 하는 곳
// 0은 갈 수 없는 곳
// 1은 갈 수 있는 곳


//void intru(int y, int x);
int dp(int y, int x);
void print_list(int y, int x, bool include_zero);
void make_list();

int main()
{
    //make_list();
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            cache[i][j]=-1;
    char temp;
    direc.push_back(make_pair(1,0));
    direc.push_back(make_pair(0,1));
    direc.push_back(make_pair(-1,0));
    direc.push_back(make_pair(0,-1));
    char input;
    
    cin>>M>>N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>temp;
            if(temp=='1'){
                map[i][j]=1;
                cache[i][j]=0;
                
            }else{
                map[i][j]=0;
                //cache[i][j]=-1;
            }
        }
    }
    
    //print_list(M, N, true);
    
    for(int i=0;i<N;i++){
        if(!map[0][i])
            dp(0,i);
    }
    
    //print_list(M, N, true);
    
    for(int i=0;i<N;i++){
        if(cache[0][i]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    
    

    return 0;
}

int dp(int y, int x){
    //if(y<0 || y>=M || x<0 || x>=N) return r=0;
    int &r=cache[y][x]; // 초기 cache에는 0이나 -1이 들어가있음
    //cout<<y<<"\t"<<x<<endl;
    if(r!=-1) return r;
    if(y==M-1) return r=1;
    
    r=0; //이거 안하면 segmentation fault 뜸
    
    for(int i=0;i<direc.size();i++){
        int next_y=y+direc[i].first, next_x=x+direc[i].second;
        if(next_y>=0 && next_y<M && next_x>=0 && next_x<N)
            if(!map[next_y][next_x]) // map배열에는 0이나 1이 들어가 있음
                r=max(r, dp(next_y, next_x));
    }
    return r;
    
}

void make_list(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(j==1) cout<<"1";
            else cout<<"0";
        }
        cout<<endl;
    }
}

void print_list(int y, int x, bool include_zero){
    int start, end;
    if(include_zero) start=end=0;
    else start=end=1;
    
    for(int i=start;i<y+end;i++){
        for(int j=start;j<x+end;j++)
            cout<<cache[i][j]<<"\t";
        cout<<endl;
    }
    return;
}

/*
void intru(int y, int x){
    if(y<0 || y>=M || x<0 || x>=N) return;
    if(visited[y][x]) return;
    if(y==M-1){
        ret=true;
        return;
    }
    visited[y][x]=1;
    for(int i=0;i<direc.size();i++){
        int next_y=y+direc[i].first, next_x=x+direc[i].second;
        if(!map[next_y][next_x])
            intru(next_y, next_x);
    }
    visited[y][x]=0;
    
}

*/