#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 20005
#define M 60005
#define INF 0x7fffffff
int u[M],v[M],w[M],cap[M],first[N],next[M];
int pre[N],d[N];
int e,n,m;
queue<int> q;
bool inq[N];
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
int f(int i,int j)
{
    return i*m+j;
}
void insert(int i,int j,int cost,int val)
{
    u[e]=i;
    v[e]=j;
    w[e]=cost;
    cap[e]=val;
    next[e]=first[u[e]];
    first[u[e]]=e++;
    u[e]=j;
    v[e]=i;
    w[e]=-cost;
    cap[e]=0;
    next[e]=first[u[e]];
    first[u[e]]=e++;
}
void spfa(int s,int cnt)
{
    memset(inq,false,sizeof(inq));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<=cnt;i++) d[i]=INF;
    d[s]=0;
    q.push(s);
    inq[s]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        inq[x]=false;
        for(int i=first[x];i+1;i=next[i])
        {
            int y=v[i];
            if(cap[i]&&d[x]+w[i]<d[y])
            {
                d[y]=d[x]+w[i];
                pre[y]=i;
                if(!inq[y])
                {
                    q.push(y);
                    inq[y]=true;
                }
            }
        }
    }
}
int min_cost(int s,int t,int cnt)
{
    int ans=0;
    while(1)
    {

        spfa(s,cnt);
        if(d[t]==INF) break;
        int tmp=INF;
        for(int i=pre[t];i+1;i=pre[u[i]])
        tmp=min(tmp,cap[i]);
        for(int i=pre[t];i+1;i=pre[u[i]])
        {
            cap[i]-=tmp;
            cap[i^1]+=tmp;
        }
        ans+=tmp*d[t];
    }

    return ans;
}
int main()
{
    //freopen("in.cpp","r",stdin);
   int T,i,j,k;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d: ",cas++);
       scanf("%d %d",&n,&m);
       init();

       int tot=n*m, ans=0;
       for(i=0;i<n;i++)
       for(j=0;j<m;j++)
       {

           scanf("%d",&k);
           if(i==0&&j==0) insert(f(i,j),f(i,j)+tot,0,2),ans+=k;
           else if(i==n-1&&j==m-1) insert(f(i,j),f(i,j)+tot,0,2), ans+=k;
           else insert(f(i,j),f(i,j)+tot,-k,1);
       }
       for(i=0;i<n;i++)
       for(j=0;j<m;j++)
       {
         if(j+1<m) insert(f(i,j)+tot,f(i,j+1),0,2);
         if(i+1<n) insert(f(i,j)+tot,f(i+1,j),0,2);
       }
       printf("%d\n",-min_cost(0,2*tot-1,2*tot)+ans);

    }
   return 0;

}
