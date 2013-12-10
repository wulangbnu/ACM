#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 20005
#define M 50005
int u[M],v[M],first[N],next[M];
int g[N],dfn[N],low[N],stk[N];
int scc,cnt,top;
int in[N],out[N];
void init()
{
    memset(first,-1,sizeof(first));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(dfn,-1,sizeof(dfn));
    scc=cnt=top=0;
}
void Tarjan(int x)
{
    dfn[x]=low[x]=cnt++;
    stk[top++]=x;
    for(int e=first[x];e+1;e=next[e])
    {
        if(dfn[v[e] ]==-1) Tarjan(v[e]);
        low[x]=min(low[x],low[v[e]]);
    }
    if(dfn[x]==low[x])
    {
        int tmp;
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
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u[i],&v[i]);
            next[i]=first[u[i] ];
            first[u[i] ]=i;
        }
        for(i=1;i<=n;i++)
        if(dfn[i]==-1) Tarjan(i);
        if(scc==1)
        {
            puts("0");
            continue;
        }
        for(i=0;i<m;i++)
        {
            j=g[u[i]],k=g[v[i]];
            if(j!=k)
            {
                in[k]++;
                out[j]++;
            }
        }
        for(j=k=i=0;i<scc;i++)
        {
            if(out[i]==0) j++;
            if(in[i]==0)  k++;
        }
        printf("%d\n",max(j,k));

    }
    return 0;
}























