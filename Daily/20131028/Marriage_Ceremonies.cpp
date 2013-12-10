#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=16;
int n,dp[N+1][1<<N],a[N][N];
int dfs(int x,int state){
    if(dp[x][state]!=-1) return dp[x][state];
    if(state==0) return dp[x][state]=0;
    for(int i=0;i<n;i++){
        if(!(state&(1<<i))) continue;
        dp[x][state]=max(dp[x][state],a[x-1][i]+dfs(x-1,state^(1<<i)));
    }
    return dp[x][state];
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++cas,dfs(n,(1<<n)-1));
    }
    return 0;
}
