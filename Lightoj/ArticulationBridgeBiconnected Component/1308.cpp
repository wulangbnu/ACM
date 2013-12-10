#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 10005
#define M 40005
vector<int> mem[N];
bool cut[N];
int u[M],v[m],first[N],next[M];
int dfn[N],low[N],stk[N];
int scc,cnt,top;
void init()
{
   memset(first,-1,sizeof(first));
   memset(dfn,-1,sizeof(dfn));
   memset(cut,false,sizeof(cut));
   scc=cnt=top=0;
}
void Tarjan(int x,int fa)
{
    dfn[x]=low[x]=cnt++;
    int tot=0,f=0;
    for(int e=first[x];e+1;e=next[e])
    {
        if(dfn[v[e]]==-1)
        {
            Tarjan(v[e],x);
            tot++;
            low[x]=min(low[x],low[v[e]]);
            if((fa==-1&&tot>1)||(fa!=-1&&dfn[x]<=low[v[e]]))
            {
              f=1;
              mem[scc].clear();
              while(stk[top-1]!=x)
              mem[scc].push_back(stk[--top]);
              mem[scc].push_back(x);
              ++scc;
            }

        }
        else if(v[e]!=fa)
        low[x]=min(low[x],dfn[v[e]]);
    }
    if(f) cut[x]=1;
}
int main()
{
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
            v[i+1]=u[i];
            u[i+1]=v[i];
            next[i+1]=first[u[i+1]];
            first[u[i+1]]=i+1;
        }
        for(i=0;i<n;i++)
        if(dfn[i]==-1) Tarjan(i,-1);


    }
    return 0;
}
