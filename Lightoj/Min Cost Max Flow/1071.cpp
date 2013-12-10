#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 20005
#define M 180000
#define INF 0x7fffffff
int u[M],v[M],w[M],cap[M],first[N],next[M];
int g[N][N],cnt;
bool inq[N];
int d[N],pre[N];
queue<int> q;
void init()
{
    memset(first,-1,sizeof(first));
    cnt=0;
}
void insert(int f,int t,int cost,int val)
{
    u[cnt]=f; v[cnt]=t;
    w[cnt]=cost; cap[cnt]=val;
    next[cnt]=first[f];
    first[f]=cnt++;
    u[cnt]=t; v[cnt]=f;
    w[cnt]=-cost; cap[cnt]=0;
    next[cnt]=first[t];
    first[t]=cnt++;

}
void spfa(int s,int n)
{
    memset(inq,false,sizeof(inq));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<=n;i++) d[i]=INF;
    d[s]=0;
    q.push(s);
    inq[s]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        inq[x]=false;

        printf("%d %d ***\n",x,d[x]);getchar();
        for(int e=first[x];e+1;e=next[e])
        {
            int y=v[e];
            if(cap[e]&&d[x]+w[e]<d[y])
            {
                d[y]=d[x]+w[e];
                pre[y]=e;
                if(!inq[y])
                {
                    q.push(y);
                    inq[y]=true;
                }
            }
        }
    }

}
int min_cost(int s,int t,int n)
{
    int ans=0,e;
    while(1)
    {
       spfa(s,n);
       printf("%d \n",d[t]);
       if(d[t]==INF) break;
       int tmp=INF;
       for(e=pre[t];e+1;e=pre[u[e]])
       {
           tmp=min(tmp,cap[e]);
       }
       for(e=pre[t];e+1;e=pre[u[e]])
       {
           cap[e]-=tmp;
           cap[e^1]+=tmp;
       }
       printf("%d %d\n",d[t],tmp);
       ans+=tmp*d[t];
    }
    return ans;

}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        scanf("%d",&g[i][j]);

        int tot=n*m;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(i==0&&j==0) continue;
            if(i==n-1&&j==m-1) continue;
            int tmp=i*m+j;
            insert(tmp,tmp+tot,-g[i][j],1);
        }
        insert(0,tot,-g[0][0],2);
        insert(tot-1,tot+tot-1,-g[n-1][m-1],2);

        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
          if(j+1<m)
          {
              insert(i*m+j+tot,i*m+(j+1),0,2);
          }
          if(i+1<=n)
          {
              insert(i*m+j+tot,(i+1)*m+j,0,2);
          }
        }
        insert(2*tot,0,0,2);
        insert(2*tot-1,2*tot+1,0,2);
        printf("%d\n",-min_cost(2*tot,2*tot+1,2*tot+2)-g[0][0]-g[n-1][m-1]);

    }
    return 0;
}
