#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 505
#define M 10005
#define INF 100000000
int u[M],v[M],w[M],first[N],next[M];
int shop[N];
int f[N][N];
struct dd
{
    int a,b;
    bool operator <(const dd tt )const
    {
        if(a!=tt.a) return a>tt.a;
        return b<tt.b;
    }

}d[N],tmp;
struct Point
{
    dd dis;
    int s;
    bool operator <(const Point tt) const
    {
        return tt.dis<dis;
    }
}p,pp;
priority_queue<Point> q;
int main()
{
    freopen("in.cpp","r",stdin);

    int T,n,m,t,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        memset(first,-1,sizeof(first));
        memset(shop,0,sizeof(shop));
        memset(f,0,sizeof(f));

        scanf("%d %d %d",&n,&m,&t);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        f[i][j]=0;

        for(i=0;i<t;i++)
        {
            scanf("%d",&j);
            shop[j]=1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u[i],&v[i],&w[i]);
            next[i]=first[u[i]];
            first[u[i]]=i;
        }

        for(i=0;i<n;i++)
        d[i].a=0,d[i].b=INF;

        d[0].a=shop[0] , d[0].b=0;
        if(shop[0]) f[0][0]=1;
        p.dis=d[0],p.s=0;
        q.push(p);
        while(!q.empty())
        {
            p=q.top();
            q.pop();
            //if(d[p.s]<p.dis) continue;
            for(int e=first[p.s];e+1;e=next[e])
            {
                i=(shop[v[e]]&&f[p.s][v[e]]==0);
               tmp.a=p.dis.a+i;
               tmp.b=p.dis.b+w[e];
               if(tmp<d[v[e]])
               {
                   memcpy(f[v[e]],f[p.s],sizeof(f[p.s]));
                   if(i)  f[v[e]][v[e]]=1;
                   d[v[e]]=tmp;
                   pp.dis=d[v[e]];
                   pp.s=v[e];
                   q.push(pp);
               }
            }


            //printf("__________%d\n",p.s);
           // for(i=0;i<n;i++)
            //printf("****%d %d %d\n",i,d[i].a,d[i].b);

            //puts("");

         }

          if(d[n-1].b<INF)
          printf("%d %d\n",d[n-1].a,d[n-1].b);
          else puts("Impossible");

    }
    return 0;
}
