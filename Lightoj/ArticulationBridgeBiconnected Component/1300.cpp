#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
#define M 40005
int u[M],v[M],first[N],next[M];
bool p[M];
int get[N];
int dfn[N],low[N];
int cnt,scc,top;
void init()
{
    memset(first,-1,sizeof(first));
    memset(dfn,-1,sizeof(dfn));
    memset(p,false,sizeof(p));
    memset(get,-1,sizeof(get));
    cnt=scc=top=0;
}
void Tarjan(int x,int fa)
{
    dfn[x]=low[x]=cnt++;
    for(int e=first[x];e+1;e=next[e])
    {
        if(dfn[v[e]]==-1)
        {
            Tarjan(v[e],x);
            low[x]=min(low[x],low[v[e]]);
            if(dfn[x]<low[v[e]]) p[e]=1;
        }
        else if(v[e]!=fa)
        low[x]=min(low[x],dfn[v[e]]);
    }

}
void dfs(int x)
{
    get[x]=scc;
    for(int e=first[x];e+1;e=next[e])
    {
        if(p[e]) continue;
        if(get[v[e]]==-1)
        {
            dfn[v[e]]=1-dfn[x];
           dfs(v[e]);
        }

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
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d",&n,&m);
        for(i=0;i<2*m;i+=2)
        {
            scanf("%d %d",&u[i],&v[i]);
            next[i]=first[u[i]];
            first[u[i]]=i;
            u[i+1]=v[i];
            v[i+1]=u[i];
            next[i+1]=first[u[i+1]];
            first[u[i+1]]=i+1;
        }
        for(i=0;i<n;i++)
        if(dfn[i]==-1) Tarjan(i,-1);
        for(i=0;i<2*m;i++)
        if(p[i])
        {
            if(i&1) p[i-1]=1;
            else p[i+1]=1;
        }

        memset(dfn,0,sizeof(dfn));
        for(i=0;i<n;i++)
        if(get[i]==-1)
        {
            dfs(i);
            scc++;
        }
        memset(low,0,sizeof(low));
        for(i=0;i<2*m;i++)
        if(!p[i])
        {
            if(dfn[u[i]]==dfn[v[i]])
            low[get[u[i]]]=1;
        }
        for(i=j=0;i<n;i++)
        if(low[get[i]]) j++;

        printf("%d\n",j);

    }
    return 0;
}






