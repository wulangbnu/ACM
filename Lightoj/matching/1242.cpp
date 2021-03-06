#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 205
#define M 80005
int u[M],v[M],first[N],next[M];
int out[N],r[N],pre[N];
int my[N],e;
bool get[N];
void init()
{
    memset(first,-1,sizeof(first));
    memset(get,false,sizeof(get));
    e=0;
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
    for(int i=1;i<=n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
    }
    return ans;
}
void dfs2(int x,int le)
{
   if(get[x]) return;
   get[x]=true;
   r[x]=le;
   for(int i=first[x];i+1;i=next[i])
   {
       if(!get[v[i]])
       {
            out[x]++;
            pre[v[i]]=x;
            dfs2(v[i],le+1);

       }

   }
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
        memset(out,0,sizeof(out));
        memset(r,0,sizeof(r));
        memset(pre,0,sizeof(pre));

        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&j,&k);
            insert(j,k);
            insert(k,j);
        }
        dfs2(1,1);

        init();
        scanf("%d",&m);
        for(i=1;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            insert(j+n,k+n);
            insert(k+n,j+n);
        }
        dfs2(n+1,1);

        int top=0;
        for(i=1;i<=n;i++)
        top=max(top,r[i]);

        for(k=1;k<=top;k++)
        {

         init();
         for(i=1;i<=n;i++)
         for(j=n+1;j<=n+m;j++)
         {
             if(r[i]-k+1==r[j]&&out[j]<=out[i])
             {
                 if(r[pre[i]]-k+1==r[pre[j]]&&out[pre[j]]<=out[pre[i]])
                 insert(i,j);
                 insert(pre[i],pre[j]);
             }

          }

         if(hk(n)==m) break;
         }
        if(k<=top) puts("Yes");
        else puts("No");

    }
    return 0;
}


