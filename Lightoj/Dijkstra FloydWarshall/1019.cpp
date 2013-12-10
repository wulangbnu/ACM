#include<cstdio>
#include<cstring>
#define N 105
#define INF 100000000
int g[N][N],d[N],v[N];
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,n,m,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        g[i][j]=INF;
        while(m--)
        {
            scanf("%d %d %d",&i,&j,&k);
            if(k<g[i][j])
            g[i][j]=g[j][i]=k;

        }
        memset(v,0,sizeof(v));
        for(i=2;i<=n;i++) d[i]=INF;
        for(i=0;i<n-1;i++)
        {
            int tmp=INF,x;
            for(j=1;j<=n;j++) if(!v[j]&&d[j]<tmp) tmp=d[x=j];
            v[x]=1;
            for(j=1;j<=n;j++)
            if(d[j]>d[x]+g[x][j])
            d[j]=d[x]+g[x][j];
        }
        if(d[n]<INF) printf("%d\n",d[n]);
        else puts("Impossible");

    }
    return 0;
}
