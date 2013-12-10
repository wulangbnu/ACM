#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define  N  40005
#define  M  350000
int u[M],v[M],first[N],next[M];
int distx[N],disty[N],my[N],mx[N];
int e;
int a[8]={-2,-1, 1, 2,2,1,-1,-2};
int b[8]={-1,-2,-2,-1,1,2,2 ,1};
bool g[205][205];
queue<int>  q;
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t)
{
    u[e]=f;
    v[e]=t;
    next[e]=first[u[e]];
    first[u[e]]=e++;
}
bool bfs(int n)
{
   memset(distx,-1,sizeof(distx));
   memset(disty,-1,sizeof(disty));
   bool flag=false;
   for(int i=0;i<n;i++)
   if(mx[i]==-1)
   {
         q.push(i);
         distx[i]=0;
   }
   while(!q.empty())
   {
       int x=q.front();
       q.pop();
       for(int i=first[x];i+1;i=next[i])
       {
           int y=v[i];
           if(disty[y]!=-1) continue;
           disty[y]=distx[x]+1;
           if(my[y]==-1) flag=true;
           else
           {
               distx[my[y]]=disty[y]+1;
               q.push(my[y]);
           }
       }

   }

   return flag;
}
bool dfs(int x)
{
    for(int i=first[x];i+1;i=next[i])
    {
        int y=v[i];
        if(disty[y]==distx[x]+1)
        {
            disty[y]=-1;
            if(my[y]==-1||dfs(my[y]))
            {
                my[y]=x;
                mx[x]=y;
                return true;
            }

        }
    }
    return false;
}
int hk(int n)
{
   memset(mx,-1,sizeof(mx));
   memset(my,-1,sizeof(my));
   int ans=0;
   while(bfs(n))
   {
       for(int i=0;i<n;i++)
       if(mx[i]==-1&&dfs(i)) ans++;
   }
   return ans;
}
int main()
{
    //freopen("in.cpp","r",stdin);

  int T,n,m,i,j,k,cas=1;
  scanf("%d",&T);
  while(T--)
  {
      printf("Case %d: ",cas++);
      init();
      scanf("%d %d %d",&n,&m,&k);
      memset(g,false,sizeof(g));
      int ans=n*m-k;
      while(k--)
      {
          scanf("%d %d",&i,&j);
          g[i-1][j-1]=true;
      }
      for(i=0;i<n;i++)
      for(j=0;j<m;j++)
      {
          if(g[i][j]) continue;
          for(int k=0;k<8;k++)
          {
              if(i+a[k]<0||i+a[k]>n-1||j+b[k]<0||j+b[k]>m-1) continue;
              if(g[i+a[k]][j+b[k]]) continue;
              insert(i*m+j,(i+a[k])*m+j+b[k]);
          }
      }
      printf("%d\n",ans-hk(n*m)/2);

  }
  return 0;
}




