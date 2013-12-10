#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
#define M 1000000
int u[M],v[M],first[N],next[M];
int my[N],mx[N],e;
bool get[N],kill[N];
char g[105][105];
int a[N],n,m,tot;
void init()
{
    memset(first,-1,sizeof(first));
    tot=e=0;
}
void insert(int f,int t)
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
                mx[x]=y;
                return true;
            }
        }
    }
    return false;
}
int hk(int n)
{
    memset(my,-1,sizeof(my));
    memset(mx,-1,sizeof(mx));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
    }
    return ans;

}
void dfs2(int x,int y)
{
   if(get[x]||get[y]) return;
   get[x]=get[y]=true;
   if(y==-1) return;
   for(int i=first[x];i+1;i=next[i])
   {

    if(kill[v[i]]) continue;
    for(int j=first[y];j+1;j=next[j])
    {
      if(v[i]==v[j]) kill[v[i]]=true;
    }
   }
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
       printf("Case %d: ",cas++);
       init();
       int cnt=0;
       scanf("%d %d",&n,&m);
       for(i=0;i<n;i++)
       scanf("%s",g[i]);
       for(i=0;i<n;i++)
       for(j=0;j<m;j++)
       if(g[i][j]=='.')
       a[cnt++]=i*m+j;

       for(i=0;i<cnt;i++)
       for(j=i+1;j<cnt;j++)
       {
           if(a[i]/m==a[j]/m)
           {
               int tmp=a[j]%m;
               for(k=a[i]%m+1;k<tmp;k++)
               if(g[a[i]/m][k]=='W') break;
               if(k==tmp)
               {
                 insert(i,j);
                 insert(j,i);
                // printf("***%d %d\n",i,j);
               }

           }
           if(a[i]%m==a[j]%m)
           {
               int tmp=a[j]%m;
               for(k=a[i]/m+1;k<a[j]/m;k++)
               if(g[k][tmp]=='W') break;
               if(k==a[j]/m)
               {
                 insert(i,j);
                 insert(j,i);
                // printf("***%d %d\n",i,j);
               }

           }
       }
       int ans=cnt-hk(cnt)/2;
       printf("%d\n",ans);
       //for(i=0;i<cnt;i++)
       //printf("%d %d\n",i,mx[i]);

       memset(kill,false,sizeof(kill));
       memset(get,false,sizeof(get));
       for(i=0;i<cnt;i++)
       dfs2(i,mx[i]);

       for(k=i=0;i<cnt;i++)
       {
           if(!kill[i])
           {
              u[k++]=i;
              if(mx[i]!=-1)
              kill[mx[i]]=true;
           }
           else u[k++]=mx[i];
       }
       for(i=0;i<k;i++)
       g[a[u[i]]/m][a[u[i]]%m]='T';
       for(i=0;i<n;i++)
       puts(g[i]);

    }
    return 0;
}
