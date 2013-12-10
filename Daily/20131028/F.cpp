#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=3000+10;
const int M=N*N;
const int INF=0x3f3f3f3f;
int g[N][N],dmin[N],pre[N],n,m,q;
bool mark[N][N],get[N];
int dp[N][N];
vector<int> adj[N];
int query[N][N];
int doit(){
    memset(get,false,sizeof(get));
    memset(mark,false,sizeof(mark));
    memset(dmin,0x3f,sizeof(dmin));
    int ret=0;
    get[0]=true;
    for(int i=0;i<n;i++){
         dmin[i]=g[i][0];
         pre[i]=0;
         adj[i].clear();
    }
    for(int k=0;k<n-1;k++){
        int tmp=INF+1,x;
        for(int i=0;i<n;i++){
            if(get[i]) continue;
            if(dmin[i]<tmp) tmp=dmin[x=i];
        }
        ret+=tmp;
        mark[x][pre[x]]=mark[pre[x]][x]=true;
        adj[x].push_back(pre[x]);
        adj[pre[x]].push_back(x);
        get[x]=true;
        for(int i=0;i<n;i++)
        if(g[x][i]<dmin[i]){
            dmin[i]=g[x][i];
            pre[i]=x;
        }
    }
    return ret;
}
void dfs(int x,int fa,int root){
    if(fa==root) dp[root][x]=INF;
    else dp[root][x]=g[root][x];
    for(int i=0;i<adj[x].size();i++){
        int y=adj[x][i];
        if(y==fa) continue;
        dfs(y,x,root);
        dp[root][x]=min(dp[root][x],dp[root][y]);
    }
}
int a,b,c;
void dfs(int x,int fa){
    c=min(c,dp[x][a]);
    for(int i=0;i<adj[x].size();i++){
        int y=adj[x][i];
        if(y==fa) continue;
        dfs(y,x);
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)&&n+m){
        memset(g,0x3f,sizeof(g));
        while(m--){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            g[i][j]=g[j][i]=min(g[i][j],k);
        }
        int res=doit();
        //printf("~~ %d\n",res);
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<n;i++) dfs(i,-1,i);
        scanf("%d",&q);
        double ans=0.0;

        memset(query,0x3f,sizeof(query));
        for(int re=0;re<q;re++){
            int v;
            scanf("%d%d%d",&a,&b,&v);
            if(!mark[a][b]){
                ans+=res;
                continue;
            }

            if(a>b) swap(a,b);
            if(query[a][b]==INF){
                c=INF;
                dfs(b,a);
                query[a][b]=c;
            }
            else c=query[a][b];
            ans+=res-g[a][b]+min(v,c);
        }
        printf("%.4f\n",ans/q);
    }
    return 0;
}
