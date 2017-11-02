#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> >child(10001, vector<int>(2,-1));
vector<vector<int> >height(10001, vector<int>(0));

vector<bool> visited(10001, 1);
vector<int> inord;
int n, idx, a, b;
int long_level, long_max;
int max_height=-1;

int get_root();
void inorder(int level, int idx);
void get_long();

int main(){
    int root=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>idx>>a>>b;
        child[idx][0]=a;
        child[idx][1]=b;
        if(a!=-1) visited[a]=0;
        if(b!=-1) visited[b]=0;
    }
    
    root=get_root();
    inorder(1, root);
    get_long();
    cout<<long_level<<" "<<long_max<<endl;
    
    return 0;
}

int get_root(){
    int ret=0;
    for(int i=1;i<=n;i++){
        if(visited[i]){
            ret=i;
            break;
        }
    }
    return ret;
}

void inorder(int level, int idx){
    if(idx==-1) return;
    if(level > max_height)
        max_height=level;
    
    height[level].push_back(idx);
    
    inorder(level+1, child[idx][0]);
    inord.push_back(idx);
    inorder(level+1, child[idx][1]);
}

void get_long(){
    int left_idx, right_idx, left_val, right_val, cur;
    
    for(int i=1;i<=max_height;i++){
        if(height[i].size()==0) break;
        left_idx=height[i][0];
        right_idx=height[i][height[i].size()-1];
        for(int j=0;j<inord.size();j++){
            if(inord[j]==left_idx){
                left_val=j;
                break;
            }
        }
        for(int j=inord.size()-1;j>=0;j--){
            if(inord[j]==right_idx){
                right_val=j;
                break;
            }
        }
        
        cur=right_val-left_val+1;
        if(long_max<cur){
            long_max=cur;
            long_level=i;
        }
    }
}