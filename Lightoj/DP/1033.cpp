#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;
char s[N],t[N];
int dp[N][N];
int doit(int n,int m){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return n+m-2*dp[n][m];
}
int main(){

    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",s+1);
        n=strlen(s+1);
        for(i=1;i<=n;i++)
        t[n+1-i]=s[i];
        int ans=n-1;
        for(i=1;i<n;i++){
            ans=min(ans,doit(i,n-i));
            ans=min(ans,doit(i,n-1-i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
