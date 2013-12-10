#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;
const int INF=0x80808080;
int a[N],dp[N][N];
int dfs(int x,int y){
    if(dp[x][y]!=INF) return dp[x][y];
    if(x>y) return 0;
    int k=0;
    for(int i=x;i<=y;i++){
        k+=a[i];
        dp[x][y]=max(dp[x][y],k-dfs(i+1,y));
    }
    k=0;
    for(int i=y;i>=x;i--){
        k+=a[i];
        dp[x][y]=max(dp[x][y],k-dfs(x,i-1));
    }
    return dp[x][y];
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(dp,0x80,sizeof(dp));
        printf("%d\n",dfs(1,n));
    }
    return 0;
}
