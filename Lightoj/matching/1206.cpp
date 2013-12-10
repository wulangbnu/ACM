#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 505
#define M 250005
int u[M],v[M],first[N],next[M];
int my[N],e;
bool get[N];
struct Point
{
    int h,m,a,b,c,d;
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
    for(int i=0;i<n;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
    }
    return ans;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d:%d %d %d %d %d",&p[i].h,&p[i].m,&p[i].a,&p[i].b,&p[i].c,&p[i].d);
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            int m=p[i].m+abs(p[i].a-p[i].c)+abs(p[i].b-p[i].d)+abs(p[j].a-p[i].c)+abs(p[j].b-p[i].d);
            int h=p[i].h+m/60;
            m%=60;
            if(h<p[j].h||(h==p[j].h&&m<p[j].m)) insert(i,j);
        }
        printf("%d\n",n-hk(n));
    }
    return 0;
}







