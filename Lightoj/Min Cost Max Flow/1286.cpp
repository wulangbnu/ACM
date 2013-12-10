#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200+10;
const int M=205*205*2+100;
const int INF=0x3f3f3f3f;
int u[M],v[M],cap[M],flow[M],first[N],next[M],e;
int q[N],dist[N],work[N],s,t;
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val)
{
    u[e]=f; v[e]=t; cap[e]=val; flow[e]=0;
    next[e]=first[u[e]]; first[u[e]]=e++;
    u[e]=t; v[e]=f; cap[e]=0; flow[e]=0;
    next[e]=first[u[e]]; first[u[e]]=e++;
}
bool bfs()
{
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    int l=0,r=0;
    q[r++]=s;
    while(l<r){
        int x=q[l++];
        for(int i=first[x];i+1;i=next[i]){
            if(flow[i]<cap[i]&&dist[v[i]]==-1){
                dist[v[i]]=dist[x]+1;
                q[r++]=v[i];
            }
        }
    }
    return dist[t]!=-1;
}
int dfs(int x,int val)
{
    if(x==t) return val;
    for(int &i=work[x];i+1;i=next[i]){
        int y=v[i],tmp;
        if(flow[i]<cap[i]&&dist[y]==dist[x]+1&&(tmp=dfs(y,min(val,cap[i]-flow[i])))>0){
            flow[i]+=tmp;
            flow[i^1]-=tmp;
            return tmp;
        }
    }
    return 0;
}
int dinic(int n)
{
    int ans=0;
    while(bfs()){
        for(int i=0;i<=n;i++) work[i]=first[i];
        while(1){
            int tmp=dfs(s,INF);
            if(tmp==0) break;
            ans+=tmp;
        }
    }
    return ans;
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&m,&n);
        int ans=0;
        s=0; t=m+n+1;
        for(i=1;i<=m;i++){
            scanf("%d",&j);
            insert(s,i,j);
            ans+=j;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&j);
            insert(i+m,t,j);
        }
        for(i=1;i<=m;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&j);
                insert(i,j+m,INF);
            }
        }
        printf("Case %d: %d\n",cas++,ans-dinic(t));
    }
    return 0;
}
