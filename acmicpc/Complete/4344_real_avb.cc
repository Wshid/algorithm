#include<iostream>

using namespace std;

int c,n;

int main(){
    int score[1000][1000]={-1};
    double sum[1000]={0};
    double ret[1000]={0};
    double avg=0;
    cin>>c;
    for(int i=0; i<c;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>score[i][j];
            sum[i]+=score[i][j];
        }
        
        double count=0;
        for(int j=0;j<n;j++){
            if(score[i][j]>(sum[i]/n)){
               count++; 
            }
        }
        ret[i]=(count/n)*100;
    }
    
    cout.precision(3);
    cout<<fixed;
    for(int i=0;i<c;i++)
        cout<<ret[i]<<"%"<<endl;
    return 0;
}