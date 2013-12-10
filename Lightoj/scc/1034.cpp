#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
#define M 100005
int u[M],v[M],first[N],next[M];
int g[N],dfn[N],low[N],stk[N];
int scc,cnt,top;
int in[N];
void init()
{
    memset(dfn,-1,sizeof(dfn));
    memset(first,-1,sizeof(first));
    top=scc=cnt=0;
}
void Tarjan(int x)
{
    dfn[x]=low[x]=cnt++;
    stk[top++]=x;
    for(int e=first[x];e+1;e=next[e])
    {
        if(dfn[v[e]]==-1) Tarjan(v[e]);
        low[x]=min(low[x],low[v[e]]);
    }
    int tmp;
    if(low[x]==dfn[x])
    {
      do
      {
        tmp=stk[--top];
        g[tmp]=scc;
        low[tmp]=N;
      }while(tmp!=x);
      scc++;
    }

}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
      init();
      memset(in,0,sizeof(in));
      printf("Case %d: ",cas++);
      scanf("%d %d",&n,&m);
      for(i=0;i<m;i++)
      {
          scanf("%d %d",&u[i],&v[i]);
          next[i]=first[u[i]];
          first[u[i]]=i;
      }
      for(i=1;i<=n;i++)
      if(dfn[i]==-1) Tarjan(i);
      for(i=0;i<m;i++)
      if(g[u[i]]!=g[v[i]]) in[g[v[i]]]++;
      for(j=i=0;i<scc;i++)
      if(in[i]==0) j++;
      printf("%d\n",j);


    }
    return 0;
}













