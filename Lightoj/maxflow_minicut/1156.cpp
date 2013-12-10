#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;
#define N 205
#define M 40005
#define INF 100000
int u[M],v[M],first[N],next[M],cap[M],flow[M];
int dist[N],e,s,t,work[N];
queue<int> q;
struct Point
{
    bool flag;
    int d;
}p[N];
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val)
{
    u[e]=f, v[e]=t, cap[e]=val, flow[e]=0;
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

    int T,n,m,h,i,j,k,cas=1;
    char str[15];
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d",&n,&h);
        for(i=1;i<=n;i++)
        {
            scanf("%s",str);
            p[i].flag=(str[0]=='B');
            p[i].d=atoi(str+2);
        }

        int x=0,y=h;
        s=0, t=2*n+1;
        while(x<y)
        {
            int mid=(x+y)/2;
            init();
            for(i=1;i<=n;i++)
            {
                if(p[i].flag) insert(i,i+n,2);
                else insert(i,i+n,1);
                if(p[i].d<=mid) insert(s,i,2);
                if(h-p[i].d<=mid) insert(i+n,t,2);
            }
            for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
               if(p[j].d-p[i].d<=mid)
               {
                   insert(i+n,j,2);
                   //insert(j+n,i,2);
               }
               else break;
            }
            int tmp=dinic(2*n+2);
            if(tmp>=2) y=mid;
            else x=mid+1;

        }
        printf("%d\n",x);

    }
    return 0;
}
