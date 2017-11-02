#include<iostream>
#include<limits>
#include<vector>

using namespace std;

const int INT_MAX=numeric_limits<int>::max();
class RMQ{
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array){
        n=array.size();
        rangeMin.resize(n*4); //size를 4배로 잡아주어야
        init(array,0,n-1,1); //
    }
    
    int init(const vector<int>& array, int left, int right, int node){
        if(left==right)
            return rangeMin[node]=array[left];
        int mid=(left+right)/2;
        int leftmin=init(array, left, mid, node*2); // root 노드는 1 왼쪽은 2배, 오른쪽 2배+1
        int rightmin=init(array, mid+1, right, node*2+1);
        return rangeMin[node]=min(leftmin, rightmin);
    }
    
    int query(int left, int right, int node, int nodeLeft, int nodeRight){ // 노드가 나타내는 범위가 nodeLeft, nodeRight이므로
        if(right<nodeLeft || nodeRight<left) return INT_MAX;
        //if(nodeLeft<=left && right<=nodeRight) return rangeMin[node]; // 반대로 생각해야함!
        if(left<=nodeLeft && nodeRight<=right) return rangeMin[node];
        
        int mid=(nodeLeft+nodeRight)/2
        return min(query(left,right,node*2,nodeLeft,mid),
                min(query(left,right,node*2+1,mid+1,nodeRight)));
        
    }
    
    int query(int left, int right){
        query(left,right,1,0,n-1);
    }
    
    int update(int value, int node, int left, int right){
        if(left==right) return array[node]=value;
        
            
    }
};

int main()
{
    return 0;
}