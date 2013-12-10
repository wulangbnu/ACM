#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2000+10;
int a[N],dp[N][N],n;
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;a[i+n]=a[i],i++) scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=2*n;i++) dp[i][i]=1;
        for(int k=2;k<=n;k++)
        for(int i=1;i+k-1<=2*n;i++){
            int j=i+k-1;
            dp[i][j]=max(max(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1]+(a[i]==a[j])*2);
        }
        int ans=0;
        for(int i=1;i+n-1<=2*n;i++) ans=max(ans,dp[i][i+n-1]);
        for(int i=1;i+n-2<=2*n;i++) ans=max(ans,dp[i][i+n-2]+1);
        printf("%d\n",ans);
    }
    return 0;
}
