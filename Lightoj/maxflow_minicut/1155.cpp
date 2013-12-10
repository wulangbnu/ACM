#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N  205
#define M  40005
#define INF 100005
int u[M],v[M],first[N],next[M],cap[M],flow[M];
int dist[N],e,s,t,work[N],a[N];
queue<int> q;
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val)
{
    u[e]=f, v[e]=t, cap[e]=val,flow[e]=0;
    next[e]=first[u[e]], first[u[e]]=e++;
    u[e]=t, v[e]=f, cap[e]=0, flow[e]=0;
    next[e]=first[u[e]], first[u[e]]=e++;
}
bool bfs()
{
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=first[x];i+1;i=next[i])
        {
            int y=v[i];
            if(flow[i]<cap[i]&&dist[y]==-1)
            {
                dist[y]=dist[x]+1;
                q.push(y);
            }
        }
    }
    return dist[t]!=-1;
}
int dfs(int x,int val)
{
    if(x==t) return val;
    for(int i=work[x];i+1;i=next[i])
    {
        work[x]=i;
        int y=v[i],tmp;
        if(flow[i]<cap[i]&&dist[y]==dist[x]+1&&(tmp=dfs(y,min(val,cap[i]-flow[i])))>0)
        {
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
    while(bfs())
    {
        for(int i=0;i<n;i++) work[i]=first[i];
        while(1)
        {
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
    int b,d;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            insert(i,i+n,a[i]);
        }

        scanf("%d",&m);
        while(m--)
        {
            scanf("%d %d %d",&i,&j,&k);
            insert(i+n,j,k);
        }
        s=0,t=2*n+1;
        scanf("%d %d",&b,&d);
        for(i=0;i<b;i++)
        {
            scanf("%d",&j);
            insert(s,j,a[j]);
        }
        for(i=0;i<d;i++)
        {
            scanf("%d",&j);
            insert(j+n,t,a[j]);
        }
        printf("%d\n",dinic(2*n+2));
    }
    return 0;
}
