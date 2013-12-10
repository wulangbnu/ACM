#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=3000000+10;
char str[N];
void doit(char str[],int n){
    if(n==0){
       printf("%02X\n",n);
       return;
    }
    while(n){
        int x=0;
        if((n>>7)) x+=(1<<7);
        x+=n&((1<<7)-1);
        printf("%02X",x);
        n>>=7;
    }
    for(int i=0;str[i];i++) printf("%02X",str[i]);
    puts("");
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    gets(str);
    while(T--){
        gets(str);
        doit(str,strlen(str));
    }
    return 0;
}
