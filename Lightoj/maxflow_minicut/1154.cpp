#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 205
#define M 40005
#define INF 100000
#define EPS 1e-7
int u[M],v[M],first[N],next[M],cap[M],flow[M];
int dist[N],work[N],e,s,t;
queue<int> q;
struct Point
{
    double x,y;
    int num,val;
}p[N];
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val,int val2)
{
    u[e]=f; v[e]=t; cap[e]=val; flow[e]=0;
    next[e]=first[u[e]];  first[u[e]]=e++;
    u[e]=t; v[e]=f; cap[e]=val2; flow[e]=0;
    next[e]=first[u[e]];  first[u[e]]=e++;
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
        if(flow[i]<cap[i]&&dist[y]==dist[x]+1&&(tmp=dfs(y,min(cap[i]-flow[i],val)))>0)
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

   int  T,n,m,i,j,k,cas=1;
   double d;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d:",cas++);
       scanf("%d %lf",&n,&d);
       int sum=0;
       for(i=1;i<=n;i++)
       {
          scanf("%lf %lf %d %d",&p[i].x,&p[i].y,&p[i].num,&p[i].val);
          if(p[i].num>0) sum+=p[i].num;
       }
       bool flag=true;
       for(k=1;k<=n;k++)
       {
           s=0;
           t=2*n+1;
           init();
           for(i=1;i<=n;i++)
           {
               if(p[i].num>0) insert(s,i,p[i].num,0);
               insert(i,n+i,p[i].val,0);
           }
           for(i=1;i<=n;i++)
           for(j=i+1;j<=n;j++)
           {
               if((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)<d*d+EPS)
               {
                   insert(i+n,j,INF,0);
                   insert(j+n,i,INF,0);
               }
           }
           insert(k,t,INF,0);
           if(dinic(2*n+1)==sum)
           {
               flag=false;
               printf(" %d",k-1);
           }
       }
       if(flag) puts(" -1");
       else puts("");

   }
   return 0;
}







