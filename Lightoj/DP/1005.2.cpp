#include<cstdio>
#include<cstring>
typedef long long ll;
const int N=35;
ll dp[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        if(m>n){
            puts("0");
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=1;i<=n;i++)
        for(j=m;j>=1;j--){
            dp[j]+=dp[j-1]*(n-(j-1));
        }
        printf("%lld\n",dp[m]);
    }
    return 0;
}


