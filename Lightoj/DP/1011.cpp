#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[20][1<<16];
int a[20][20];
int main(){
   // freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(i=0;i<n;i++)
        for(j=0;j<(1<<n);j++){
            if(dp[i][j]==-1) continue;
            for(k=0;k<n;k++){
                if(j&(1<<k)) continue;
                int &tmp=dp[i+1][j|(1<<k)];
                tmp=max(tmp,dp[i][j]+a[i+1][k]);
            }
        }
        printf("%d\n",dp[n][(1<<n)-1]);
    }
    return 0;
}
