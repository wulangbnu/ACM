#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100+10;
int dp[N];
int doit(int x){
    if(dp[x]!=-1) return dp[x];
    int ans=x/2+1;
    for(int i=2;i<x;i++){
        if(x%i) continue;
        ans=min(ans,doit(i)* (x/i/2+1) );
    }
    return dp[x]=ans;
}
int main(){
    //freopen("in.cpp","r",stdin);
    //freopen("out2.cpp","w",stdout);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<N;i++) printf("%d %d\n",i,doit(i));
    return 0;
}
