#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int node[27][2];
int n;
char tmp[2], idx;
vector<char> ret;

void order(int idx, int mode);
void print_ret();

int main(){
    memset(node, -1, sizeof(node));
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>idx;
        for(int j=0;j<2;j++){
            cin>>tmp[j];
            if(tmp[j]=='.')
                node[int(idx)-64][j]=-1;
            else
                node[int(idx)-64][j]=int(tmp[j])-64;
        }
    }
    
    for(int i=1;i<=3;i++){
        order(1, i);
        print_ret();
    }
    return 0;
}

void order(int idx, int mode){
    if(idx==-1) return;
    
    switch(mode){
        case 1:
            ret.push_back(char(idx+64));
            order(node[idx][0], mode);
            order(node[idx][1], mode);
            break;
        case 2:
            order(node[idx][0], mode);
            ret.push_back(char(idx+64));
            order(node[idx][1], mode);
            break;
        case 3:
            order(node[idx][0], mode);
            order(node[idx][1], mode);
            ret.push_back(char(idx+64));
            break;
        default:
        cout<<"ERROR"<<endl;
        exit(1);
    }
}

void print_ret(){
    for(int i=0;i<ret.size();i++)
        cout<<ret[i];
    cout<<endl;
    ret.resize(0);
}