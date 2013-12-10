#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105
#define M 2005
#define INF 1000000000
int d[N][N],g[N][N],p[N];
int get[N][N];
int main()
{

    //freopen("in.cpp","r",stdin);

   int T,n,m,i,j,k,c,s,t;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {

       printf("Case %d:\n",cas++);

       scanf("%d %d",&n,&m);
       for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       g[i][j]=INF;
       for(i=0;i<n;i++)
       scanf("%d",&p[i]);
       while(m--)
       {
           scanf("%d %d %d",&i,&j,&k);
           if(k<g[i][j]) g[i][j]=g[j][i]=k;
       }

       scanf("%d",&m);
       while(m--)
       {
           scanf("%d %d %d",&c,&s,&t);

           memset(get,0,sizeof(get));
           for(i=0;i<n;i++)
           for(j=0;j<=c;j++)
           d[i][j]=INF;
           for(i=0;i<=c;i++)
           d[s][i]=i*p[s];

           for(i=0;i<n*(c+1);i++)
           {
               int tmp=INF+1,x,y;
               for(j=0;j<n;j++)
               for(k=0;k<=c;k++)
               if(d[j][k]<tmp&&!get[j][k])  tmp=d[x=j][y=k];
               get[x][y]=1;

               if(x==t) break;

               for(j=1;j+y<=c;j++)
               d[x][j+y]=min(d[x][j+y],d[x][y]+j*p[x]);

               for(j=0;j<n;j++)
               for(k=g[x][j];k<=c;k++)
               d[j][k-g[x][j]]=min(d[j][k-g[x][j]],d[x][k]);

           }
           if(d[t][0]<INF)
           printf("%d\n",d[t][0]);
           else puts("impossible");



       }

   }

   return 0;
}
