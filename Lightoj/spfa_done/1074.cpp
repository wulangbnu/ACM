#include<cstdio>
#define N 205
#define M 205*205
#define INF 1000000000
int u[M],v[M],w[M];
int p[N],d[N];
int n,m;
void spfa()
{

    int i,j,flag;
    for(i=2;i<=n;i++) d[i]=INF;
    d[1]=0;
    for(i=1;i<=n-1;i++)
    {
        flag=1;
        for(j=0;j<m;j++)
        if(d[v[j]]>d[u[j]]+w[j]&&d[u[j]]!=INF)
        {
            d[v[j]]=d[u[j]]+w[j];
            flag=0;
        }
        if(flag) break;
    }
    for(i=0;i<m;i++)
    if(d[v[i]]>d[u[i]]+w[i]&&d[u[i]]!=INF) p[v[i]]=-1;

}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d:\n",cas++);

        scanf("%d",&n);
        for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u[i],&v[i]);
            j=p[v[i]]-p[u[i]];
            w[i]=j*j*j;

        }
        spfa();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&i);
            if(d[i]>=INF||d[i]<3||p[i]==-1) puts("?");
            else printf("%d\n",d[i]);

        }

    }
    return 0;
}
