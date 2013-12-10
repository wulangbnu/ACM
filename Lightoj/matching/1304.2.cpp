#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
#define M 1000005
int u[M],v[M],first[N],next[M];
int my[N],e;
bool get[N];
char g[105][105];
struct r_block
{
    int r,s,t;
}r[N];
struct c_block
{
    int c,s,t;
}c[N];

void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int  f,int t)
{
    u[e]=f;
    v[e]=t;
    next[e]=first[u[e]];
    first[u[e]]=e++;
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
   //freopen("in.cpp","r",stdin);

   int T,n,m,i,j,k,s,t,cas=1;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d: ",cas++);
       init();
       scanf("%d %d",&n,&m);
       for(i=0;i<n;i++)
       scanf("%s",g[i]);

       int r_cnt=0;
       for(i=0;i<n;i++)
       for(s=0;s<m;s++)
       {
           if(g[i][s]=='W') continue;
           k=0;
           for(t=s;t<m;t++)
           {
               if(g[i][t]=='.') k=1;
               if(g[i][t]=='W') break;
           }
           if(k)
           {
              r[r_cnt].r=i;
              r[r_cnt].s=s;
              r[r_cnt].t=t-1;
              r_cnt++;
           }
           s=t;
       }

       int c_cnt=0;
       for(i=0;i<m;i++)
       for(s=0;s<n;s++)
       {
           if(g[s][i]=='W') continue;
           k=0;
           for(t=s;t<n;t++)
           {
               if(g[t][i]=='.') k=1;
               if(g[t][i]=='W') break;
           }
           if(k)
           {
               c[c_cnt].c=i;
               c[c_cnt].s=s;
               c[c_cnt].t=t-1;
               c_cnt++;
           }
           s=t;
       }
       for(i=0;i<r_cnt;i++)
       for(j=0;j<c_cnt;j++)
       {
         if(g[r[i].r][c[j].c]=='.'&&r[i].r>=c[j].s&&r[i].r<=c[j].t&&c[j].c>=r[i].s&&c[j].c<=r[i].t)
         insert(i,j);
       }
       printf("%d\n",hk(r_cnt));
       for(i=0;i<c_cnt;i++)
       if(my[i]!=-1)
       {
           g[r[my[i]].r][c[i].c]='T';
       }
       for(i=0;i<n;i++)
       puts(g[i]);
   }
   return 0;
}
