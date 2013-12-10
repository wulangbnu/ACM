#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105
#define M 2500
int u[M],v[M],first[N],next[M];
int my[N],e;
bool get[N];
struct Point
{
    int a,b,c;
}p[N];
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
        for(i=1;i<=n+m;i++)
        scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
        for(i=1;i<=n;i++)
        for(j=n+1;j<=n+m;j++)
        if(abs(p[i].a-p[j].a)<=12&&abs(p[i].b-p[j].b)<=5&&p[i].c==p[j].c)
        insert(i,j-n);
        printf("%d\n",hk(n));
    }
    return 0;
}
