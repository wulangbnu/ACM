#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105
#define M 10005
char g[55][55];
int u[M],v[M],first[N],next[M];
int my[N],e;
int n,m;
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
bool check_r(int i,int j)
{
    for(int k=0;k<m;k++)
    if(g[i][k]=='1'&&g[j][k]=='1') return true;
    return false;
}
bool check_c(int i,int j)
{
    for(int k=0;k<n;k++)
    if(g[k][i]=='1'&&g[k][j]=='1') return true;
    return false;
}
int main()
{
    freopen("in.cpp","r",stdin);
    int T,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%s",g[i]);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(g[i][j]=='0')
        {
            insert(i,j+n);
            insert(j+n,i);
        }
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        if(!check_r(i,j))
        {
            insert(i,j);
            insert(j,i);
        }
        for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
        if(!check_c(i,j))
        {
            insert(i+n,j+n);
            insert(j+n,i+n);
        }
        printf("%d\n",n+m-hk(n+m)/2);

    }
    return 0;
}
