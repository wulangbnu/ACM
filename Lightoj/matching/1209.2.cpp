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
}p[N],q[N];
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
    for(int i=0;i<n;i++)
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

        int s=0,t=0;

        for(i=1;i<=n;i++)
        {
           scanf("%s",str);
           if(str[0]=='M')
           {
               p[s].x=str[1]-'0';
               scanf("%s",str);
               p[s++].y=str[1]-'0';
           }
           else
           {
               q[t].x=str[1]-'0';
               scanf("%s",str);
               q[t++].y=str[1]-'0';
           }
        }
        for(i=0;i<s;i++)
        for(j=0;j<t;j++)
        if(p[i].x==q[j].y||p[i].y==q[j].x)
        {
            insert(i,j);

        }
        printf("%d\n",s+t-hk(s));
    }
    return 0;
}
