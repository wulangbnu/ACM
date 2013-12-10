#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 505
#define M 2500005
int u[M],v[M],first[N],next[M];
int my[N],e;
bool get[N];
struct Point
{
    int x,y;
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
    int res=0;
    for(int i=1;i<=n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) res++;
    }
    return res;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,f,m,i,j,k;
    int cas=1;
    char str[5];
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d %d %d",&m,&f,&n);
        for(i=1;i<=n;i++)
        {
           scanf("%s",str);
           p[i].x=str[1]-'0';
           if(str[0]=='F') p[i].x+=m;
           scanf("%s",str);
           p[i].y=str[1]-'0';
           if(str[0]=='F') p[i].y+=m;

        }
        for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        if(p[i].x==p[j].y||p[i].y==p[j].x)
        {
            insert(i,j);
            insert(j,i);
        }
        printf("%d\n",n-(hk(n)+1)/2);
    }
    return 0;
}
