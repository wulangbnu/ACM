#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;
int dp[N][N],y[N],pre[N];
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,w,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d%d",&n,&w,&m);
        for(i=1;i<=n;i++){
            scanf("%d%d",&j,&y[i]);
        }
        sort(y+1,y+1+n);
        for(i=1;i<=n;i++)
            pre[i]=lower_bound(y+1,y+1+n,y[i]-w)-y;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[pre[i]-1][j-1]+i-pre[i]+1);
            }
        printf("%d\n",dp[n][m]);

    }
    return 0;
}

