#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1005
#define M 10005
int u[M],v[M],first[N],next[M];
int my[N],e;
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
    for(int i=1;i<=n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
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
        scanf("%d %d",&n,&m);
        while(m--)
        {
            scanf("%d %d",&i,&j);
            insert(i,j);
        }
        printf("%d\n",n-hk(n));

    }
    return 0;
}
