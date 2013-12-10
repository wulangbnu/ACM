#include<cstdio>
#include<cmath>
#define N 105
#define INF 2000000000
#define EPS 1e-5
double g[N][N];
int main()
{
   // freopen("in.cpp","r",stdin);

   int T,n,m,k,s,i,j,t;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {


       printf("Case %d: ",cas++);

       scanf("%d %d %d %d",&n,&m,&s,&k);
       for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       g[i][j]=0.0;
       while(m--)
       {
           scanf("%d %d %d",&i,&j,&t);
           g[i][j]=g[j][i]=t/100.0;
       }
       for(t=0;t<n;t++)
       for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       if(g[i][t]*g[t][j]>g[i][j])
       g[i][j]=g[i][t]*g[t][j];
       double tmp=g[0][n-1];
       printf("%f\n",1/tmp*s*2*k);

   }
   return 0;
}
