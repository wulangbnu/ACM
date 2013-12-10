#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
#define N 105
#define M 1005
#define INF 100005
int u[M],v[M],first[N],next[M],cap[M],flow[M];
int dist[N],work[N],e,s,t;
queue<int> q;
map<string,int> mp;
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
    char str[10];
    string ss;
    scanf("%d",&T);
    mp["XXL"]=1, mp["XL"]=2, mp["L"]=3;
    mp["M"]=4,   mp["S"]=5,  mp["XS"]=6;
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d",&n,&m);
        s=0,t=m+7;
        for(i=1;i<=6;i++)
        insert(s,i,n);
        for(i=0;i<m;i++)
        {
          scanf("%s",str);
          ss=str;
          insert(mp[ss],i+7,1);
          scanf("%s",str);
          ss=str;
          insert(mp[ss],i+7,1);

          insert(i+7,t,1);
        }
        if(dinic(m+7+1)==m) puts("YES");
        else puts("NO");

    }
    return 0;
}
