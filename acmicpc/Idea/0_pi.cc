#include<iostream>
#include<vector>
#include<string>

using namespaces std;

const int INF=1000000000;
String N;

int classify(int a, int b){ // a~b구간의 난이도를 구한다.
    String M=N.substr(a, b-a+1);
    if(M==string(M.size(), M[0])) return 1;
    
    bool progressive=true;
    for(int i=0;i<M.size()-1;i++){
        if((M[i+1]-M[i])!=(M[1]-M[0])) progressive=false;
    }
    if(progressive) return 2;
    
    bool progressive=true;
    for(int i=0;i<M.size()-1;i++){
        if((M[i+2]-M[i])) 
    }
}