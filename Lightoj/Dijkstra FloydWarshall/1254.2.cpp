#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 105
#define M 2005
#define INF 1000000000
int d[N][N],p[N];
int u[M],v[M],w[M],first[N],next[M];
struct Point
{
    int val,a,b;
    bool operator <(const Point tt) const
    {
        return val>tt.val;
    }
}pp;
priority_queue<Point> q;
int main()
{

    //freopen("in.cpp","r",stdin);

   int T,n,m,i,j,k,c,s,t,val,a,b;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {

       printf("Case %d:\n",cas++);

       memset(first,-1,sizeof(first));
       scanf("%d %d",&n,&m);
       for(i=0;i<n;i++)
       scanf("%d",&p[i]);
       for(i=0;i<2*m;i+=2)
       {
           scanf("%d %d %d",&u[i],&v[i],&w[i]);
           next[i]=first[u[i]];
           first[u[i]]=i;

           u[i+1]=v[i],v[i+1]=u[i],w[i+1]=w[i];
           next[i+1]=first[u[i+1]];
           first[u[i+1]]=i+1;
       }

       scanf("%d",&m);
       while(m--)
       {
           scanf("%d %d %d",&c,&s,&t);


           for(i=0;i<n;i++)
           for(j=0;j<=c;j++)
           d[i][j]=INF;
           while(!q.empty()) q.pop();

           d[s][0]=0;
           pp.val=d[s][0], pp.a=s, pp.b=0;
           q.push(pp);
           while(!q.empty())
           {

             pp=q.top();
             q.pop();
             val=pp.val,a=pp.a,b=pp.b;
             if(a==t) break;

             if(d[a][b]!=val) continue;
             for(i=1;i+b<=c;i++)
             if(d[a][i+b]>d[a][b]+i*p[a])
             {
                 d[a][i+b]=d[a][b]+i*p[a];
                 pp.a=a,pp.b=i+b,pp.val=d[a][i+b];
                 q.push(pp);
            }

             for(int e=first[a];e+1;e=next[e])
             if(b>=w[e]&&d[v[e]][b-w[e]]>d[a][b])
             {
                 d[v[e]][b-w[e]]=d[a][b];
                 pp.a=v[e],pp.b=b-w[e],pp.val=d[a][b];
                 q.push(pp);
             }


           }
           if(d[t][0]<INF)
           printf("%d\n",d[t][0]);
           else puts("impossible");
      }

   }
       return 0;
}
