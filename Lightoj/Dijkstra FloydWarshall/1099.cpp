#include<cstdio>
#include<cstring>
#define N 5005
#define INF 1000000000
#define M 200005
int d[N][2],vv[N][2];
int u[M],v[M],w[M],first[N],next[M];
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

        memset(first,-1,sizeof(first));
        memset(vv,0,sizeof(vv));
        for(i=0;i<2*m;i+=2)
        {
            scanf("%d %d %d",&u[i],&v[i],&w[i]);
            next[i]=first[u[i] ];
            first[u[i] ]=i;
            v[i+1]=u[i];u[i+1]=v[i];w[i+1]=w[i];
            next[i+1]=first[u[i+1]];
            first[u[i+1]]=i+1;
        }
        for(i=0;i<=n;i++) d[i][0]=d[i][1]=INF;
        d[1][0]=0;
        d[1][1]=INF;
        for(i=0;i<4*n;i++)
        {
            int tmp=INF,x,y;
            for(j=1;j<=n;j++)
            for(k=0;k<2;k++)
            if(d[j][k]<=tmp&&vv[j][k]<2) tmp=d[x=j][y=k];

            vv[x][y]++;
            for(k=first[x];k+1;k=next[k])
            {
                j=v[k];
                tmp=d[x][y]+w[k];
                if(tmp<d[j][0]) d[j][1]=d[j][0],d[j][0]=tmp;

                if(tmp>d[j][0]&&tmp<d[j][1]) d[j][1]=tmp;
            }
        }
        printf("%d\n",d[n][1]);

    }

    return 0;
}


