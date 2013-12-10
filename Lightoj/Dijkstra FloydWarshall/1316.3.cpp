#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 505
#define M 10005
#define INF 100000000
int u[M],v[M],w[M],first[N],next[M];
int d[N][16];
bool f[N][16][N];
int shop[N];
struct Point
{
    int a,b,c;
    bool operator <(const Point tt) const
    {
        if(b!=tt.b) b<tt.b;
        return c>tt.c;
    }
}p,pp;
priority_queue<Point> q;
int main()
{

    //freopen("in.cpp","r",stdin);

    int T,n,m,s,i,j,k,e;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        memset(first,-1,sizeof(first));
        memset(shop,0,sizeof(shop));
        memset(f,false,sizeof(f));
        scanf("%d %d %d",&n,&m,&s);
        for(i=0;i<s;i++)
        {
            scanf("%d",&j);
            shop[j]=true;
        }
        for(e=0;e<m;e++)
        {
            scanf("%d %d %d",&u[e],&v[e],&w[e]);
            next[e]=first[u[e]];
            first[u[e]]=e;
        }
        for(i=0;i<=n;i++)
        for(j=0;j<=s;j++)
        d[i][j]=INF;
        d[0][shop[0]]=0;
        if(shop[0]) f[0][1][0]=true;
        p.a=0, p.b=shop[0], p.c=0;
        q.push(p);
        while(!q.empty())
        {
            pp=q.top();
            q.pop();
            i=pp.a,j=pp.b;
            //if(d[i][j]!=pp.c) continue;

            for(e=first[i];e+1;e=next[e])
            {
                k=0;
                if(!f[i][j][v[e]]&&shop[v[e]]) k=1;

                if(d[v[e]][j+k]>d[i][j]+w[e])
                {
                    d[v[e]][j+k]=d[i][j]+w[e];
                    p.a=v[e],  p.b=j+k, p.c=d[v[e]][j+k];
                    q.push(p);
                    memcpy(f[v[e]][j+k],f[i][j],sizeof(f[i][j]));
                    f[v[e]][j+k][v[e]]=1;
                }

             }


        }
        j=-1;
        for(i=0;i<=s;i++)
        if(d[n-1][i]<INF) j=i;

        if(j!=-1) printf("%d %d\n",j,d[n-1][j]);
        else  puts("Impossible");

      }

      return 0;
}


