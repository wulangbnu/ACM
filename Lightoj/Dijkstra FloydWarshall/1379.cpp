#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
#define N 10005
#define M 50005
#define INF 1000000005
typedef pair<int,int> pii;
struct Edge
{
    int u,v,w;
    bool operator <(const Edge tt) const
    {
        return w<tt.w;
    }
}e[M];
int n;
int first[N],next[M];
int d[N];
priority_queue<pii,vector<pii>,greater<pii> >q;
int dijkstra(int s,int t,int ans)
{
    for(int i=1;i<=n;i++) d[i]=INF;
    d[s]=0;
    q.push(make_pair(d[s],s));
    while(!q.empty())
    {
        pii tmp=q.top();
        q.pop();
        int x=tmp.second;
        if(tmp.first!=d[x]) continue;
        for(int i=first[x];i+1;i=next[i])
        {
           if(e[i].w>ans) continue;
           if(d[x]+e[i].w<d[e[i].v])
           {
               d[e[i].v ]=d[x]+e[i].w;
               q.push(make_pair(d[e[i].v],e[i].v));
           }
        }
    }
    return d[t];

}
int main()
{
   // freopen("in.cpp","r",stdin);

   int T,m,i,j,k,s,t,p;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {
     printf("Case %d: ",cas++);
     scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
     memset(first,-1,sizeof(first));
     for(i=0;i<m;i++)
     scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
     sort(e,e+m);
     for(i=0;i<m;i++)
     {
        next[i]=first[e[i].u];
        first[e[i].u]=i;
     }
     j=dijkstra(s,t,INF);

     if(j>p) puts("-1");
     else
     {
         for(i=m-1;i>=0;i--)
         {
              j=dijkstra(s,e[i].u,e[i].w);
              j+=dijkstra(e[i].v,t,e[i].w);
              j+=e[i].w;
              if(j<=p) break;
         }

         printf("%d\n",e[i].w);
     }
   }
    return 0;
}














