#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105
#define M 10005
int u[M],v[M],first[N],next[M];
int a[N],b[N];
int cnt;
int my[N];
bool get[N];
void insert(int f,int t)
{
    u[cnt]=f;
    v[cnt]=t;
    next[cnt]=first[u[cnt]];
    first[u[cnt]]=cnt++;
}
bool dfs(int x)
{
    for(int e=first[x];e+1;e=next[e])
    {
        int y=v[e];
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
int main()
{
    freopen("in.cpp","r",stdin);

   int T,n,m,i,j,k;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d: ",cas++);
       memset(first,-1,sizeof(first));
       cnt=0;
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
       scanf("%d",&m);
       for(j=1;j<=m;j++)
       scanf("%d",&b[j]);
       for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
       if(b[j]%a[i]==0) insert(i,j);
       printf("%d\n",hk(n));
   }
   return 0;
}
