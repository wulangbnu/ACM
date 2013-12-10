#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=20+10;
const int INF=0x3f3f3f3f;
int dp[N][N],n;
char str[N][N];
int dfs(int x,int y,int type){
    if(x>n||y>n) return -INF;
    if(dp[x][y]!=INF) return dp[x][y];
    if(x==n&&y==n) return dp[x][y]=(str[x][y]=='a')-(str[x][y]=='b');

    int ret=0;
    if(type==0) ret=(str[x][y]=='a')-(str[x][y]=='b');
    else ret=(str[x][y]=='b')-(str[x][y]=='a');
    return dp[x][y]=ret-max(dfs(x+1,y,1-type),dfs(x,y+1,1-type));
}
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        memset(dp,0x3f,sizeof(dp));
        int ans=dfs(1,1,0);
//        for(int i=1;i<=n;i++,puts(""))
//        for(int j=1;j<=n;j++)
//        printf("%5d",dp[i][j]);
//        printf("%d\n",ans);
        if(ans>0) puts("FIRST");
        else if(ans==0) puts("DRAW");
        else if(ans<0) puts("SECOND");
    }
    return 0;
}
