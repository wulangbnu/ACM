#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 405
#define M 5005
int u[M],v[M],first[N],next[M];
int my[N];
bool get[N];
int n,m,e;
char g[25][25];
int a[4]={-1,0,1,0};
int b[4]={0,-1,0,1};
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
int hk()
{
    memset(my,-1,sizeof(my));
    int ans=0;
    for(int i=0;i<n*m;i++)
    {
        memset(get,false,sizeof(get));
        if(dfs(i)) ans++;
    }
    return ans;
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
        int ans=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%s",g[i]);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(g[i][j]=='o')
            {
                ans++;
                continue;
            }
            for(k=0;k<4;k++)
            {
                if(i+a[k]>n-1||i+a[k]<0||j+b[k]<0||j+b[k]>m-1) continue;
                if(g[i+a[k]][j+b[k]]=='o') continue;
                insert(i*m+j,(i+a[k])*m+j+b[k]);
            }

         }
         i=hk()/2;
        printf("%d\n",n*m-ans-i*2+i);
    }
    return 0;
}
