#include<iostream>


class SquareMatrix{
    public:
        SquareMatrix(int _n){
            n=_n;
            arr=new long long *[n];
            for(int i=0;i<n;i++){
                arr[i]=new long long [n]; // ##??
                for(int j=0;j<n;j++)
                    arr[i][j]=0;
            }
        }
        int size(void) const{ // 왜 함수 뒤에 const를 쓰지..?
            return n;
        }
        
        SquareMatrix operator * (const SquareMatrix &other){
           // if(n!=other.n) throw runtime_error("SizeNotMatched");
            SquareMatrix ret(n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++)
                        ret[i][j]+=(arr[i][j]*other.arr[k][j]);
                }
            }
            return ret;
        }
        
        long long* operator [](const int row){ // # 이거 하나로 이중 참조가 가능하다고?
            return arr[row];
        }
        

        

    private:
        int n;
        long long **arr;
};

        SquareMatrix getIdentity(int n){
            SquareMatrix ret(n);
            for(int i=0;i<n;i++) ret[i][i]=1;
            return ret;
        }

        SquareMatrix pow(const SquareMatrix &A, long long m){
            if(m==0) return getIdentity(A.size());
            if(m%2>0)return pow(A,m/2);
            SquareMatrix half=pow(A, m/2);
            return half*half;
        }