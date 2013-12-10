#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=500+10;
int g[N][N][2],dp[N][N][2];
int dfs(int x,int y,int z){
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    if(z==0) dp[x][y][z]=max(dfs(x-1,y,0),dfs(x-1,y,1))+g[x][y][0];
    else     dp[x][y][z]=max(dfs(x,y-1,0),dfs(x,y-1,1))+g[x][y][1];
    return dp[x][y][z];
}
int main(){
     //freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            scanf("%d",&k);
            g[i][j][0]=g[i][j-1][0]+k;
        }
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            scanf("%d",&k);
            g[i][j][1]=g[i-1][j][1]+k;
        }
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        dp[i][j][0]=dp[i][j][1]=-1;
        printf("%d\n",max(dfs(n,m,0),dfs(n,m,1)));
    }
    return 0;
}
