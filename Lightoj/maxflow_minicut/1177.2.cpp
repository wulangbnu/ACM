#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 105
#define M 5005
#defien INF 0x7fffffff
int u[M],v[M],next[M],first[N],cap[M],flow[M];
int dist[N],work[N],s,t,e;
queue<int> q;
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val)
{
    u[e]=f, v[e]=t, cap[e]=val, flow[e]=0;
    next[e]=first[u[e]], first[u[e]]=e++;
    u[e]=t, v[e]=f, cap[e]=val, flow[e]=0;
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
       work[i]=i;
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
      for(int i=0;i<=n;i++) work[i]=first[i];
      int tmp=dfs(s,INF);
      if(tmp==0) break;
      ans+=tmp;
    }
    return ans;
}
int main()
{
    int T,n,m,i,j,k,cas;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d",&n,&m);
        for(i=2;i<=n-1;i++)
        {
            scanf("%d",&j);
            insert()
        }
    }
}
















