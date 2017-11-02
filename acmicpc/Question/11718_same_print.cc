/* getchar을 이용해야 한다고 함 */
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main(){
    char str[101]="";
    while(1){
        gets(str);
        puts(str);
    }
    return 0;
}