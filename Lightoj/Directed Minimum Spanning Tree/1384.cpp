#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 65
#define M 10005
#define INF 0x7ffffff
int mid;
int n,ans,cnt,e[N][N];
int pre[N],stk[N],top,mark[N],begin,id[N],mincost[N];
bool u[N];

int v[M],w[M],c[M],first[N],next[M];

void dfs(int x)
{
    if(u[x]) return;
    u[x]=true;
    cnt++;
    for(int i=1;i<=n;i++)
    if(e[x][i]<INF&&!u[i]) dfs(i);
}
bool findcircle(int root)
{
    memset(u,false,sizeof(u));
    int tmp,i;
    for(i=1;i<=n;i++)
    {
        if(i==root||u[i]||id[i]!=i) continue;
        tmp=i;
        top=0;
        memset(mark,-1,sizeof(mark));
        while(tmp!=root&&mark[tmp]==-1&&!u[tmp])
        {
            u[tmp]=true;
            mark[tmp]=top;
            stk[top++]=tmp;
            tmp=pre[tmp];

        }
        if(mark[tmp]!=-1)
        {
          begin=mark[tmp];
          return true;
        }

    }
    return false;

}
void combine(int root)
{
    int i,j,col;
    col=id[stk[begin]];
    for(i=begin;i<top;i++)
    {
       id[stk[i]]=col;
       ans+=mincost[stk[i]];
       for(j=1;j<=n;j++)
       {
           if(id[j]!=j||id[j]==col) continue;
           if(e[j][stk[i]]<INF&&e[j][stk[i]]-mincost[stk[i]]<e[j][col])
           e[j][col]=e[j][stk[i]]-mincost[stk[i]];
           e[col][j]=min(e[col][j],e[stk[i]][j]);
       }

    }
    for(i=1;i<=n;i++)
    {
        if(i!=root&&id[pre[i]]==col)
        pre[i]=col;
    }
    mincost[col]=INF;
    for(i=1;i<=n;i++)
    if(i!=col&&id[i]==i&&e[i][col]<mincost[col])
    {
        mincost[col]=e[i][col];
        pre[col]=i;
    }

}
void zhuliu(int root)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        id[i]=i;
        if(i==root) continue;
        mincost[i]=INF;
        for(j=1;j<=n;j++)
        if(e[j][i]<INF&&e[j][i]<mincost[i])
        {
            mincost[i]=e[j][i];
            pre[i]=j;

        }

    }
    while(findcircle(root)) combine(root);
    for(i=1;i<=n;i++)
    if(i!=root&&id[i]==i)
    ans+=mincost[i];

}
int main()
{

    freopen("in.cpp","r",stdin);

   int T,m,i,j,k,t,cas=1,Cost;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d: ",cas++);
       scanf("%d %d %d",&n,&m,&Cost);
       int root=1;
       mid=0;
       memset(first,-1,sizeof(first));

       for(int ee=0;ee<m;ee++)
       {
           scanf("%d %d %d %d",&i,&j,&k,&t);
           i++;
           j++;
           if(i==j) continue;
           w[ee]=k;
           c[ee]=t;
           v[ee]=j;
           next[ee]=first[i];
           first[i]=ee;
       }
       for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       e[i][j]=INF;



       for(i=1;i<=n;i++)
       {
           for(int ee=first[i];ee+1;ee=next[ee])
           if(w[ee]>=mid)
           {

               e[i][v[ee]]=min(e[i][v[ee]],c[ee]);


           }

       }





       cnt=0;
       memset(u,false,sizeof(u));
       dfs(root);
       if(cnt!=n)
       {
         puts("impossible");
         continue;
       }


           ans=0;
           zhuliu(root);
           if(ans>Cost)
           {
             puts("impossible");
             continue;
           }
        int x=0,y=1000005;
        while(x<y)
        {
            mid=(x+y+1)/2;
            for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       e[i][j]=INF;
       for(i=1;i<=n;i++)
       {
           for(int ee=first[i];ee+1;ee=next[ee])
           if(w[ee]>=mid) e[i][v[ee]]=min(e[i][v[ee]],c[ee]);
       }


            cnt=0;
            memset(u,false,sizeof(u));
            dfs(root);
            if(cnt!=n) y=mid-1;
            else
            {

                ans=0;
                zhuliu(root);

              if(ans>Cost) y=mid-1;
              else x=mid;
            }

         }
         printf("%d kbps\n",x);


   }
   return 0;
}
