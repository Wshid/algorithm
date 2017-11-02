#include <iostream>
#include "squarematrix.h"


        


int main(){
    return 0;
}

long long fib(long long n){
    if(n==0) return 0;
    SquareMatrix w(2);
    w[0][0]=0;
    w[0][1]=w[1][0]=w[1][1]=1;
    return pow(w,n-1)[1][1];
}