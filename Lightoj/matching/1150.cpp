#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1000
#define M 100000
int u[M],v[M],first[N],next[M];
int my[N],e,n,mid;
bool get[N];
char g[30][30];
int vis[30][30];
typedef pair<int,int> pii;
queue<pii> q;
int a[4]={-1,0,1,0};
int b[4]={0,-1,0,1};
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t)
{
    u[e]=f;
    v[e]=t;
    next[e]=first[u[e]];
    first[u[e]]=e++;
}
bool dfs(int x)
{
    for(int i=first[x];i+1;i=next[i])
    {
        int y=v[i];
        if(!get[y])
        {
            get[y]=true;
            if(my[y]==-1||dfs(my[y]))
            {
                my[y]=x;
                return true;
            }
        }
    }
    return false;
}
int hk(int n)
{
    memset(my,-1,sizeof(my));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
    }
    return ans;
}
void bfs(int s,int t)
{
   memset(vis,-1,sizeof(vis));
   q.push(make_pair(s,t));
   vis[s][t]=0;
   while(!q.empty())
   {
      pii p=q.front();
      q.pop();
      int x=p.first,y=p.second;
      for(int i=0;i<4;i++)
      {
          if(x+a[i]<0||x+a[i]>n-1||y+b[i]<0||y+b[i]>n-1) continue;
          if(vis[x+a[i]][y+b[i]]!=-1||g[x+a[i]][y+b[i]]=='#') continue;
          vis[x+a[i]][y+b[i]]=vis[x][y]+1;
          q.push(make_pair(x+a[i],y+b[i]));
          if(g[x+a[i]][y+b[i]]=='G'&&vis[x+a[i]][y+b[i]]<=mid) insert(s*n+t,(x+a[i])*n+y+b[i]);
      }
   }
}
int main()
{
   // freopen("in.cpp","r",stdin);

    int T,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);

        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s",g[i]);

        m=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(g[i][j]=='H') m++;

        int x=1,y=650;
        while(x<y)
        {
            mid=(x+y)/2;
            init();
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            if(g[i][j]=='H') bfs(i,j);
            if(hk(n*n)==m) y=mid;
            else x=mid+1;
        }
        if(x==650) puts("Vuter Dol Kupokat");
        else printf("%d\n",x*2+2);
    }
    return 0;
}
