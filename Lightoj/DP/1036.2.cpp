#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=500+10;
int g[N][N][2],dp[N][N][2];
int main(){
    freopen("in.cpp","r",stdin);
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
        for(j=1;j<=m;j++){
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])+g[i][j][0];
            dp[i][j][1]=max(dp[i][j-1][0],dp[i][j-1][1])+g[i][j][1];
        }
        printf("%d\n",max(dp[n][m][0],dp[n][m][1]));
    }
    return 0;
}
