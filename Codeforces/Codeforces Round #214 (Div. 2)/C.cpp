#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
const int INF=0x3f3f3f3f;
int dp[105][2*N],a[105],b[105];
int n,k;
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    while(scanf("%d%d",&n,&k)==2){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);

        for(int i=0;i<=n;i++)
        for(int j=0;j<2*N;j++) dp[i][j]=-INF;

        dp[0][0+N]=0;
        for(int i=1;i<=n;i++){
             int x=a[i]-k*b[i];
             for(int j=0;j<2*N;j++){
                dp[i][j]=dp[i-1][j];
                if(j-x>=0&&j-x<2*N) dp[i][j]=max(dp[i][j],dp[i-1][j-x]+a[i]);
             }
        }

        int ans=dp[n][0+N];
        if(ans>0) printf("%d\n",ans);
        else printf("-1\n");
    }

    return 0;
}
