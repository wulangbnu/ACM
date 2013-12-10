#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 40005
#define M 800000
#define MAXN 500005
int v[M],next[M],first[N];
int distx[N],disty[N];
int my[N],mx[N],e;
bool p[MAXN];
int  c[MAXN],cnt;
queue<int> q;
int a[N];
void prime()
{
    p[0]=p[1]=true;
    for(int i=2;i*i<MAXN;i++)
    if(!p[i])
    {
        for(int j=i*i;j<MAXN;j+=i)
        p[j]=true;
    }
    for(int i=2;i<MAXN;i++)
    if(!p[i]) c[cnt++]=i;
}
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t)
{
    v[e]=t;
    next[e]=first[f];
    first[f]=e++;
}
bool bfs(int n)
{
    bool flag=false;
    memset(distx,-1,sizeof(distx));
    memset(disty,-1,sizeof(disty));
    for(int i=0;i<n;i++)
    if(mx[i]==-1)
    {
        q.push(i);
        distx[i]=0;
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=first[x];i+1;i=next[i])
        {
            int y=v[i];
            if(disty[y]!=-1) continue;
            disty[y]=distx[x]+1;
            if(my[y]==-1) flag=true;
            else
            {
               distx[my[y]]=disty[y]+1;
               q.push(my[y]);
            }
        }
    }
    return flag;
}
bool dfs(int x)
{
    for(int i=first[x];i+1;i=next[i])
    {
        int y=v[i];
        if(disty[y]==distx[x]+1)
        {
            disty[y]=-1;
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
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    int ans=0;
    while(bfs(n))
    {
        for(int i=0;i<n;i++)
        if(mx[i]==-1&&dfs(i)) ans++;
    }
    return ans;
}
int main()
{
   freopen("in.cpp","r",stdin);

  int T,n,m,i,j,k,cas=1;
  scanf("%d",&T);
  prime();

  printf("%d\n",cnt);

  while(T--)
  {
     printf("Case %d: ",cas++);
     init();
     scanf("%d",&n);
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     sort(a,a+n);
     for(i=0;i<n;i++)
     for(j=i+1;j<n;j++)
     if(a[j]%a[i]==0&&!p[a[j]/a[i]])
     {
       insert(i,j);
       insert(j,i);
       //printf("%d %d\n",a[i],a[j]);
     }
     printf("%d\n",n-hk(n)/2);
  }
  return 0;
}
