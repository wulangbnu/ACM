#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100005
#define M 300005
#define INF 100000000
int u[M],v[M],ww[M],first[N],next[M];
int d[N][11];
struct Point
{
    int a,b,w;
    bool operator < (const Point tt)const
    {
         return w>tt.w;
    }
}p;
priority_queue<Point> q;
int main()
{
    //freopen("in.cpp","r",stdin);

   int T,n,m,k,i,j,s,a,b,w;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d: ",cas++);

       scanf("%d %d %d %d",&n,&m,&k,&s);
       s++;
       memset(first,-1,sizeof(first));
       for(i=0;i<m+k;i++)
       {
           scanf("%d %d %d",&u[i],&v[i],&ww[i]);
           next[i]=first[u[i]];
           first[u[i]]=i;
       }
       for(i=0;i<n;i++)
       for(j=0;j<s;j++)
       d[i][j]=INF;
       d[0][0]=0;
       p.a=0,p.b=0,p.w=0;
       q.push(p);
       while(!q.empty())
       {
           p=q.top();
           q.pop();
           a=p.a, b=p.b, w=p.w;
          if(w!=d[a][b]) continue;
          for(int e=first[a];e+1;e=next[e])
          {
             i=(e>=m);
             if(b+i>=s) continue;
             if(d[a][b]+ww[e]<d[v[e]][b+i])
             {
                 d[v[e]][b+i]=d[a][b]+ww[e];
                 p.a=v[e], p.b=b+i, p.w=d[v[e]][b+i];
                 q.push(p);

             }
          }


       }
       int ans=INF;
       for(i=0;i<s;i++)
       ans=min(ans,d[n-1][i]);
       if(ans<INF) printf("%d\n",ans);
       else puts("Impossible");



   }
   return 0;
}
