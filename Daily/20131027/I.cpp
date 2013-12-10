#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=21+10;
const int INF=0x3f3f3f3f;
int m,n,s;
int cnt[N][N];
int dp[2][(1<<21)+10];
int dfs(int id,int x){
    if(dp[id][x]!=INF) return dp[id][x];
    if(x==0) return dp[id][x]=0;
    dp[id][x]=-INF;
    int a[N]={0};
    for(int i=0;i<n;i++){
        if((x&(1<<i))==0){
            for(int j=1;j<=m;j++)
            a[j]+=cnt[i][j];
            //if(x==1) printf("!! %d\n",i);
        }
    }
    for(int i=1;i<=m;i++) a[i]%=s;
    for(int i=0;i<n;i++){
        if((x&(1<<i))==0) continue;
        int tot=0;
        for(int j=1;j<=m;j++)
        tot+=(a[j]+cnt[i][j])/s;
        if(tot==0) dp[id][x]=max(dp[id][x],tot-dfs(1-id,x^(1<<i)));
        else       dp[id][x]=max(dp[id][x],tot+dfs(id,x^(1<<i)));
    }
    //printf("%d %d %d\n",id,x,dp[id][x]);
    return dp[id][x];
}
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d",&m,&n,&s)&&m+n+s){
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            int k,j;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&j);
                cnt[i][j]++;
            }
        }
        memset(dp,0x3f,sizeof(dp));
        printf("%d\n",dfs(0,(1<<n)-1));
    }
    return 0;
}
