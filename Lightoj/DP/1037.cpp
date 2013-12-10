#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=15;
int a[N],dp[1<<N];
char g[N][N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            scanf("%s",g[i]);
            for(j=0;j<n;j++)
            g[i][j]-='0';
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(i=0;i<(1<<n);i++){
//             printf("%d %d\n",i,dp[i]);
            for(j=0;j<n;j++){
                if(i&(1<<j)) continue;
                dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+a[j]);
                for(k=0;k<n;k++)
                    if(i&(1<<k)){
                        if(g[k][j]>0) dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+(a[j]+g[k][j]-1)/g[k][j]);
                }
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}
