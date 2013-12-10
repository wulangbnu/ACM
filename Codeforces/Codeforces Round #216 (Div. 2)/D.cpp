#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=3000+10;
const int INF=0x3f3f3f3f;
int n,m;
int p[N],sum[N];
int dp[N][N];
void dfs(int cnt,int x,int y){

    if(cnt>m) return;
    if(cnt>=dp[x][y]) return;

    dp[x][y]=cnt;
    //printf("%d %d %d\n",cnt,x,y);


    if(y>n) return;

    if(p[x]>0&&sum[y]>0) dfs(cnt+1,y+1,y+2);

    if(p[x]<100&&sum[y]>0) dfs(cnt+1,y,y+1);

    if(p[x]>0&&sum[y]<100) dfs(cnt+1,x,y+1);

}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    while(cin>>n>>m){

        for(int i=1;i<=n;i++) cin>>p[i];
        sum[n]=p[n];

        for(int i=n-1;i>=1;i--) sum[i]=max(sum[i+1],p[i]);



        memset(dp,0x3f,sizeof(dp));

        dfs(0,1,2);

        int ans=0;
        for(int i=1;i<N;i++)
        for(int j=1;j<N;j++) ans+=(dp[i][j]!=INF);

        cout<<ans<<endl;
    }
    return 0;
}
