#include<cstdio>
#include<algorithm>
using namespace std;
double dp[110];
int main(){
   // freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%lf",&dp[i]);
        for(i=n-1;i>=1;i--){
            k=min(6,n-i);
            for(j=1;j<=k;j++)
                dp[i]+=dp[i+j]/k;
        }
        printf("Case %d: %.9f\n",cas++,dp[1]);
    }
    return 0;
}
