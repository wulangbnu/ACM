#include<cstdio>
#include<cstring>
#define N 1005
#define M 4005
int u[M],v[M],w[M],d[N];
int get[N],first[N],next[M];
void dfs(int i)
{
    if(get[i]) return;
    get[i]=1;
    for(int e=first[i];e+1;e=next[e])
    dfs(v[e]);
}
int main()
{

    freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k;
    int cas=1;
    scanf("%d ",&T);
    while(T--)
    {
        printf("Case %d:",cas++);

        memset(first,-1,sizeof(first));
        memset(get,0,sizeof(get));
        scanf("%d %d ",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d ",&v[i],&u[i],&w[i]);
            next[i]=first[u[i]];
            first[u[i]]=i;
        }

        for(i=0;i<n;i++)
        {
            u[m]=n;
            v[m]=i;
            w[m++]=0;
        }
        for(i=0;i<=n;i++) d[i]=1000000000;
        d[n]=0;
        for(i=1;i<=n;i++)
        {
            k=1;
            for(j=0;j<m;j++)
            if(d[v[j]]>d[u[j]]+w[j])
            {
                d[v[j]]=d[u[j]]+w[j];
                k=0;
            }
            if(k) break;
        }
        for(k=i=0;i<m;i++)
        if(d[v[i]]>d[u[i]]+w[i])
        {
            dfs(v[i]);
            k=1;
        }
        if(k)
        {
            for(i=0;i<n;i++)
            if(get[i]) printf(" %d",i);
            puts("");
        }
        else puts(" impossible");


    }
    return 0;

}
