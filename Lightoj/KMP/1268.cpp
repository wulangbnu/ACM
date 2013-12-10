#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll MOD=1ll<<32;
char str[105];
int dp[105];
int main()
{
    freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        //printf("Case %d: ",cas++);
        scanf("%d",&n);
        scanf("%s",str); m=strlen(str);
        scanf("%s",str); k=strlen(str);
        dp[0]=1;
        for(i=1;i<=n;i++){
            dp[i]=dp[i-1]*m;
            if(i>=k) dp[i]-=dp[i-k];
            printf("%d %d\n",i,dp[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
