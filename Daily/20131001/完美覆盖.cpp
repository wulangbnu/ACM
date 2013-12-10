#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=31;
int dp[N];
void init(){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<N;i++){
        if(i&1) dp[i]=dp[i-1]+dp[i-2];
        else dp[i]=2*dp[i-1]+dp[i-2];
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    init();
    int n;
    while(scanf("%d",&n)&&n!=-1){
        if(n&1) puts("0");
        else printf("%d\n",dp[n]);
    }
    return 0;
}
