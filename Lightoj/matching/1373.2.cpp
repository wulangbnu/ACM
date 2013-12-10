#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 55
#define M 2505
int u[M],v[M],first[N],next[M];
int my[N],cnt;
bool get[N];
char g[N][N];
bool e[N][N];
int p[N],q[N];
void init()
{
    memset(first,-1,sizeof(first));
    cnt=0;
}
void insert(int f,int t)
{
    u[cnt]=f;
    v[cnt]=t;
    next[cnt]=first[u[cnt]];
    first[u[cnt]]=cnt++;
}
bool dfs(int x)
{
    for(int i=first[x];i+1;i=next[i])
    {
        int y=v[i];
        if(!get[y])
        {
            get[y]=true;
            if(my[y]==-1||dfs(my[y]))
            {
                my[y]=x;
                return true;
            }
        }
    }
    return false;
}
int hk(int n)
{
    memset(my,-1,sizeof(my));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
    }
    return ans;
}
int main()
{
     // freopen("in.cpp","r",stdin);

     int T,n,m,i,j,k,cas=1;
     scanf("%d",&T);
     while(T--)
     {
         printf("Case %d: ",cas++);
         scanf("%d %d",&n,&m);
         for(i=0;i<n;i++)
         scanf("%s",g[i]);
         for(i=0;i<n;i++)
         for(j=0;j<m;j++){
            e[i][j]=(g[i][j]=='0');
         }


         int ans=0;
         for(i=0;i<n;i++)
         for(j=0;j<m;j++)
         {
             if(e[i][j]) continue;
             int x=0,y=0;
             for(k=0;k<n;k++)
             if(!e[k][j]) p[x++]=k;
             for(k=0;k<m;k++)
             if(!e[i][k]) q[y++]=k;
             init();
             for(int s=0;s<x;s++)
             for(int t=0;t<y;t++)
             if(e[p[s]][q[t]]) insert(s,t);

             ans=max(ans,x+y-hk(x));

         }
         printf("%d\n",ans);

     }
     return 0;
}
