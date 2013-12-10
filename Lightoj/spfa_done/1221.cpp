#include<cstdio>
#define N 105
#define M 10005
#define INF 1000000000
int u[M],v[M],w[M],d[N];
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,p,i,j,k;
    int cas=1;
    scanf("%d ",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
       scanf("%d %d %d ",&n,&m,&p);
       for(i=0;i<m;i++)
       {
           scanf("%d %d %d %d",&u[i],&v[i],&j,&k);
           w[i]=p*k-j;
       }

        for(i=0;i<n;i++) d[i]=INF;
        d[0]=0;
        for(i=0;i<n;i++)
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
        for(j=i=0;i<m;i++)
        if(d[v[i]]>d[u[i]]+w[i]) j=1;
        if(j) puts("YES");
        else puts("NO");

    }
    return 0;

}
