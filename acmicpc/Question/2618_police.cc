#include<iostream>
#include<cstring>
#include<vector>
#define MAX_NW 1001

int N, W;
int y, x;
int cache[MAX_NW][2];
pair<int, int> input;

// 음.. 어쨌든 전수조사를 진행을 해야 함

int main(){
    cin>>W;
    for(int i=0;i<W;i++){
        cin>>y>>x;
        input[i]=make_pair(y, x);
        
    }
    
    
    return 0;
}


int get_dist(y1, x1, y2, x2){
    return make_pair(y2-y1, x2-x1);
}