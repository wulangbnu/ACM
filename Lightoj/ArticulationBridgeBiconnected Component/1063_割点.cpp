#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
#define M 40005
int u[M],v[M],first[N],next[M];
int dfn[N],low[N];
int cnt,ans;
void init()
{
    memset(first,-1,sizeof(first));
    memset(dfn,-1,sizeof(dfn));
    cnt=ans=0;
}
void dfs(int x,int fa)
{
     int tot=0,f=0;
    dfn[x]=low[x]=cnt++;
    for(int e=first[x];e+1;e=next[e])
    {
        if(dfn[v[e]]==-1)
        {
            dfs(v[e],x);
            tot++;
            low[x]=min(low[x],low[v[e]]);
            if(fa==-1&&tot>1) f=1;
            if(fa!=-1&&dfn[x]<=low[v[e]]) f=1;
        }
        else if(v[e]!=fa)
        low[x]=min(low[x],dfn[v[e]]);
    }
    if(f) ans++;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        init();
        printf("Case %d: ",cas++);
        scanf("%d %d",&n,&m);
        for(i=0;i<2*m;i+=2)
        {
            scanf("%d %d",&u[i],&v[i]);
            next[i]=first[u[i]];
            first[u[i]]=i;
            u[i+1]=v[i], v[i+1]=u[i];
            next[i+1]=first[u[i+1]];
            first[u[i+1]]=i+1;
        }
        for(i=1;i<=n;i++)
        if(dfn[i]==-1) dfs(i,-1);
        printf("%d\n",ans);

    }
    return 0;
}
