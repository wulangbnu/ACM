#include<cstdio>
#include<cstring>
#define N 1005
#define M 2005
int u[M],v[M],w[M],first[N],next[M];
int get[N],p[N];
int s;
void dfs(int i,int t)
{
    if(get[i]) return;
    get[i]=1;
    for(int e=first[i];e!=-1;e=next[e])
    {

        if(v[e]==s&&t+w[e]<0)
        {
            p[s]=1;
            return;
        }
        else dfs(v[e],t+w[e]);
    }
}
void dfs2(int i)
{
     if(get[i]) return;
     get[i]=1;
     for(int e=first[i];e!=-1;e=next[e])
     if(!get[v[e]]) dfs2(v[e]);
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k;
    int cas=1;
    scanf("%d ",&T);
    while(T--)
    {
        printf("Case %d:",cas++);
        memset(p,0,sizeof(p));
        memset(first,-1,sizeof(first));
        scanf("%d %d ",&n,&m);
        for(int e=0;e<m;e++)
        {
            scanf("%d %d %d",&v[e],&u[e],&w[e]);
            next[e]=first[u[e]];
            first[u[e]]=e;
        }

        for(i=0;i<n;i++)
        {
            memset(get,0,sizeof(get));
            s=i;
            dfs(i,0);
        }


        for(j=i=0;i<n;i++)
        if(p[i]) j=1;
        if(j)
        {
            memset(get,0,sizeof(get));
            for(i=0;i<n;i++)
            if(p[i]) dfs2(i);

            for(i=0;i<n;i++)
            if(get[i]) printf(" %d",i);
            puts("");
        }
        else
        {
            puts(" impossible");
        }

    }

    return 0;
}

