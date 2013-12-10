#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;
const int M=105*105*2+100;
const int INF=0x3f3f3f3f;
int u[M],v[M],first[N],cap[M],flow[M],next[M],e;
int dist[N],q[N],work[N],s,t;
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
        scanf("%d%d",&n,&m);
        s=1;
        t=n+n;
        insert(s,1+n,INF);
        insert(n,t,INF);
        for(i=2;i<=n-1;i++){
            scanf("%d",&j);
            insert(i,i+n,j);
        }
        while(m--){
            scanf("%d%d%d",&i,&j,&k);
            insert(i+n,j,k);
            insert(j+n,i,k);
        }
        printf("Case %d: %d\n",cas++,dinic(t));
    }
    return 0;
}
