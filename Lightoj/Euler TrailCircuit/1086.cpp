#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 17
#define INF 1000000000
int e[N][N],in[N];
int dp[1<<N];
int n;
int dfs(int x)
{
    if(dp[x]!=-1) return dp[x];
    if(x==0) return dp[x]=0;
    dp[x]=INF;
    for(int i=1;i<=n;i++)
    if(x&(1<<i))
    {
        for(int j=i+1;j<=n;j++)
        if(x&(1<<j)) dp[x]=min(dp[x],dfs(x^(1<<i)^(1<<j))+e[i][j]);
    }
    return dp[x];
}
int main()
{
  //freopen("in.cpp","r",stdin);
  int T,m,i,j,k,cas=1;
  scanf("%d",&T);
  while(T--)
  {
    printf("Case %d: ",cas++);
    memset(in,0,sizeof(in));
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    e[i][j]=INF;
    int ans=0;
    while(m--)
    {
        scanf("%d %d %d",&i,&j,&k);
        in[i]++;
        in[j]++;
        e[j][i]=e[i][j]=min(e[i][j],k);
        ans+=k;
    }
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
    for(k=0,i=1;i<=n;i++)
    if(in[i]&1) k|=1<<i;
    printf("%d\n",dfs(k)+ans);

  }
  return 0;
}

