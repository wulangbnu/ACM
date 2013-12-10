#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=20+10;
const int INF=0x3f3f3f3f;
int dp[N][N][N][N];
int a[N],b[N],n;
int dfs(int x1,int y1,int x2,int y2){
    if(x1>y1&&x2>y2) return dp[x1][y1][x2][y2]=0;
    if(dp[x1][y1][x2][y2]!=INF) return dp[x1][y1][x2][y2];
    dp[x1][y1][x2][y2]=-INF;
    if(x1<=y1){
        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],a[x1]-dfs(x1+1,y1,x2,y2));
        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],a[y1]-dfs(x1,y1-1,x2,y2));
    }
    if(x2<=y2) {
        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],b[x2]-dfs(x1,y1,x2+1,y2));
        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],b[y2]-dfs(x1,y1,x2,y2-1));
    }
   // printf("%d %d %d %d %d\n",x1,y1,x2,y2,dp[x1][y1][x2][y2]);
    return dp[x1][y1][x2][y2];
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++){
           scanf("%d",&a[i]);
           sum+=a[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            sum+=b[i];
        }
        memset(dp,0x3f,sizeof(dp));
        //printf("%d\n",dfs(1,n,1,n));
        printf("%d\n",(dfs(1,n,1,n)+sum)/2);
    }
    return 0;
}
