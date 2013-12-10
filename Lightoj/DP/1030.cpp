#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;
double dp[N];
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=n;i>=1;i--) scanf("%lf",&dp[i]);
        //for(i=1;i<=n;i++) scanf("%lf",&dp[i]);
        for(i=2;i<=n;i++){
            k=min(6,i-1);
            for(j=1;j<=k;j++)
            dp[i]+=dp[i-j]/k;
            //printf("%d %f\n ",i,dp[i]);
        }
        printf("%.9f\n",dp[n]);
    }
    return 0;
}
