#include<cstdio>
#define N 105
#define INF 10000000
int g[N][N];
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,s,t,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i!=j)
        g[i][j]=INF;
        while(m--)
        {
           scanf("%d %d",&i,&j);
           g[i][j]=g[j][i]=1;
        }
        scanf("%d %d",&s,&t);

        for(k=0;k<n;k++)
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(g[i][k]+g[k][j]<g[i][j]) g[i][j]=g[i][k]+g[k][j];

        for(j=i=0;i<n;i++)
        if(g[s][i]+g[i][t]>j) j=g[s][i]+g[i][t];

        printf("%d\n",j);

    }
    return 0;
}
