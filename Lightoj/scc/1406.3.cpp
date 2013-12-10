#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define N 40005
#define M 50005
#define INF  1000000000
int u[M],v[M],first[N],next[M];
int g[N],dfn[N],low[N],stk[N];
int scc,cnt,top;
int get[N],match[N];
void init()
{
    memset(first,-1,sizeof(first));
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
        scc++;
        int tmp;
        do
        {
            tmp=stk[--top];
            g[tmp]=scc;
            low[tmp]=N;
        }while(tmp!=x);

    }
}




struct edge
{
    int from,to,val,next;
}e[60000];
int vv[N],que[N],dis[N],cur[N];
void insert(int from,int to,int va)
{
    e[cnt].from=from;e[cnt].to=to;
    e[cnt].val=va;
    e[cnt].next=vv[from]; vv[from]=cnt++;
    e[cnt].from=to;e[cnt].to=from;
    e[cnt].val=0;
    e[cnt].next=vv[to]; vv[to]=cnt++;
}
bool bfs(int n,int s,int t)
{
    int head,tail,id;
    head=tail=0;
    que[tail++]=s;
    memset(dis,-1,sizeof(int)*n);
    dis[0]=0;
    while(head<tail)
    for(id=vv[que[head++] ];id!=-1;id=e[id].next)
    if(e[id].val>0&&dis[e[id].to]==-1)
    {
        dis[e[id].to]=dis[e[id].from ]+1;
        que[tail++]=e[id].to;
        if(e[id].to==t) return true;
    }
    return false;

}
int Dinic(int n,int s,int t)
{
    int maxflow=0,tmp,i;
    while(bfs(n,s,t))
    {
        int u=s,tail=0;
        for(i=0;i<n;i++) cur[i]=vv[i];
        while(cur[s]!=-1)
        if(u!=t&&cur[u]!=-1&&e[cur[u] ].val>0&&dis[u]!=-1&&dis[u]+1==dis[e[cur[u]].to])
        {
            que[tail++]=cur[u];u=e[cur[u]].to;
        }
        else if(u==t)
        {
            for(tmp=INF,i=tail-1;i>=0;i--)
            tmp=min(tmp,e[que[i]].val);
            for(maxflow+=tmp,i=tail-1;i>=0;i--)
            {
                e[que[i]].val-=tmp;
                e[que[i]^1].val+=tmp;
                if(e[que[i]].val==0) tail=i;
            }
            u=e[que[tail]].from;
        }
        else
        {
            while(tail>0&&u!=s&&cur[u]==-1)
            u=e[que[--tail]].from;
            cur[u]=e[cur[u] ].next;
        }
    }
    return maxflow;
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

        memset(vv,-1,sizeof(vv));
        cnt=0;
        for(i=0;i<m;i++)
        {
            j=g[u[i]],k=g[v[i]];
            if(j==k) continue;
            insert(j,k+scc,1);
        }
        for(i=1;i<=scc;i++)
        {
            insert(0,i,1);
            insert(i+scc,2*scc+1,1);
        }

      printf("%d\n",scc-Dinic(2*scc+2,0,2*scc+1));

    }
    return 0;
}























