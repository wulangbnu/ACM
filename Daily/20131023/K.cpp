#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=100+10;
const int INF=0x3f3f3f3f;
vector<int> adj[N];
int n,c[N],dp[N][N][2],q;
bool cmp(int x,int y){
    return c[x]<c[y];
}
int dfs(int x,int y,int z){
    if(x==1){
        if(y==0&&z==0) return 0;
        else return INF+1;
    }
    if(dp[x][y][z]!=INF) return dp[x][y][z];

    dp[x][y][z]=INF+1;
    int tot=0;
    for(int i=0;i<=adj[x].size()&&i<=y;i++){
        if(i-1>=0) tot+=c[adj[x][i-1]];
        int now=dfs(x-1,y-i,0)+tot;
        if(z==0){
            if(adj[x].size()-i>=q) now=INF+1;
        }else {
            if(adj[x].size()-i+1>=q) now=INF+1;
        }

        dp[x][y][z]=min(dp[x][y][z],now);

        if(z==1){
            now=dfs(x-1,y-i,1)+tot;
            if(adj[x].size()-i>=q) now=INF+1;
            dp[x][y][z]=min(dp[x][y][z],now);
        }
    }
    //printf("~~ %d %d %d %d\n",x,y,z,dp[x][y][z]);
    return dp[x][y][z];
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=2;i<=n;i++){
            int j;
            scanf("%d",&j);
            adj[j].push_back(i);
        }
        for(int i=2;i<=n;i++) scanf("%d",&c[i]);

        for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end(),cmp);

        //for(int i=1;i<=n;i++) printf("## %d\n",adj[i].size());

        int ans=INF;
        for(q=adj[1].size();q<=n;q++){
            memset(dp,0x3f,sizeof(dp));
            dp[1][0][0]=0;
            //printf("%d %d\n",q,dfs(n,q-adj[1].size(),1));
            if(dfs(n,q-adj[1].size(),1)<INF) ans=min(ans,dfs(n,q-adj[1].size(),1));
        }
        printf("%d\n",ans);
    }
    return 0;
}
