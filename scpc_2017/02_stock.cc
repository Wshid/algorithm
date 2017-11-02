/*
메모리제한 : 아마 재귀구현 때문인듯, 반복문 형태로 바꾸긴 해야하는데
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define BUY 1
#define SELL 0
#define MAX_N 200001
#define INF 1000000001
// 각각의 정수는 1 ~ 1,000,000,000을 의미함

using namespace std;

int Answer;
//int cache[2][MAX_N];
int cache[MAX_N];
long long input[MAX_N];
int N;


int stock(int idx, long long prev, bool status);

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
	int T, test_case;
	
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    memset(cache, -1, sizeof(cache));
        cin>>N;
        
        for(int i=1;i<=N;i++){
            cin>>input[i];
        }
        
        //cout<<stock(1,MAX_N,SELL)<<endl;
        
		Answer = stock(1,INF,SELL);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implemwent your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

int stock(int idx, int prev, bool status){
    int & ret=cache[idx];
    if(ret!=-1) return ret;
    if(idx==N){
        if(status==BUY){ // 팔아야할때, BUY한 것보다 높다면 팔아야함
            if(prev<input[idx]) return ret=2;
        }else{
            return ret=0;
        }
    }
    //ret=max(ret, );
    // 현재꺼를 선택할지 여부를 검사하기
    // 첫째항의 기본 값은 SELL일 것임
    if(status==BUY){ // 산 상태이므로 무조건 팔아야 한다.
        if(prev<input[idx]){
            ret=max(stock(idx+1, prev, status), stock(idx+1, input[idx], SELL)+2);
        }
    }else{ // SELL
        if(prev>input[idx]){
            ret=max(stock(idx+1, prev, status), stock(idx+1, input[idx], BUY)+0);
        }
    }
    return ret;
}