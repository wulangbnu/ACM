#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=35;
ll dp[N][N];
int n;
ll dfs(int x,int y){
    if(y>x||y<0) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y]=dfs(x-1,y)+dfs(x-1,y-1)*(n-(y-1));
    return dp[x][y];
}
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=1,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&k);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=1;
        printf("%lld\n",dfs(n,k));
    }
    return 0;
}
