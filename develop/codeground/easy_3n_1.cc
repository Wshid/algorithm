#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int T, K;
int level[64][2];
vector<int> k;

void initiate();
void n3plus(const int k, int value);

int main(void)
{
    int temp;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>temp;
        k.push_back(temp);
    }
    
    for(int i=0;i<T;i++)
    {
        K=k[i];
        initiate();
        n3plus(1,1);
        cout<<level[K][0]<<" "<<level[K][1]<<endl;
    }
    
    return 0;
    
}

void initiate()
{
    memset(level,-1,sizeof(level));
    level[0][0]=level[0][0]=0;
}

void n3plus(const int k, const int value)
{
   // cout<<"layer "<<k<<"========\n"<<level[k][0]<<"\t"<<level[k][1]<<endl;
    int next_min=(value-1)/3;
    int next_max=value*2;
    
    if(k>K) return;
    
    if(next_max>level[k][1]){
        level[k][1]=next_max;
        n3plus(k+1,next_max);
    }
    
    if(((value-1)%3)==0){
        cout<<"value is "<<value<<endl;
        if(next_min>level[k][0]){
            level[k][0]=next_min;
            n3plus(k+1, next_min);
        }
    }else{
        level[k][0]=next_max;
    }
    return;
}