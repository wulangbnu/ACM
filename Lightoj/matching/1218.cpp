#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105
#define M 10005
int u[M],v[M],first[N],next[M];
int my[N],mx[N],e,a[N];
bool get[N];
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
    int ans=0;
    for(int i=0;i<n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
    }
    return ans;
}
bool check(int k)
{
   for(int i=0;i<k;i++)
   for(int j=0;j<k;j++)
   {
       if(i==j) continue;
       if(a[u[j]]%a[u[i]]==0) return false;
   }


   return true;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d:",cas++);
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        if(a[j]%a[i]==0) insert(i,j);
        hk(n);
        for(k=i=0;i<n;i++)
        if(my[i]==-1) u[k++]=i;
        while(1)
        {
            if(check(k)) break;
            for(i=0;i<k;i++)
            for(j=0;j<k;j++)
            {
                if(i==j) continue;
               if(a[u[j]]%a[u[i]]==0) u[i]=mx[u[i]];
            }

        }
        for(i=0;i<k;i++)
        u[i]=a[u[i]];
        sort(u,u+k);
        for(i=0;i<k;i++)
        printf(" %d",u[i]);
        puts("");

    }
}
