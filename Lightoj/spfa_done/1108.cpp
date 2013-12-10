#include<cstdio>
#include<cstring>
#define N 1005
#define M 2005
int u[M],v[M],w[M],first[N],next[M];
int get[N],p[N];
int s;
void dfs(int i,int t)
{
   if(get[i]) return;
   get[i]=1;
   for(int e=first[i];e+1;e=next[e])
   {
       if(v[e]==s&&t+w[e]<0)
       {
           get[s]=2;
           return;
       }
       else if(!get[v[e]]) dfs(v[e],t+w[e]);
   }
}
void dfs2(int i)
{
    if(get[i]==3) return;
    get[i]=3;
    for(int e=first[i];e+1;e=next[e])
    {
        if(get[v[e]]!=3) dfs2(v[e]);
    }
}
bool check(int n)
{
    for(int i=0;i<n;i++)
    if(get[i]==2) return true;
    return false;
}
int main()
{
    freopen("in.cpp","r",stdin);

   int T,n,m,i,j,k;
   int cas=1;
   scanf("%d ",&T);
   while(T--)
   {

       printf("Case %d:",cas++);
       memset(first,-1,sizeof(first));
       memset(get,0,sizeof(get));
       scanf("%d %d ",&n,&m);
       for(int e=0;e<m;e++)
       {
          scanf("%d %d %d ",&v[e],&u[e],&w[e]);
          next[e]=first[u[e]];
          first[u[e]]=e;
       }
       for(i=0;i<n;i++)
       {
          for(j=0;j<n;j++)
          if(get[j]==1) get[j]=0;

          if(!get[i])
          {
            s=i;
            dfs(i,0);
          }

       }
       if(!check(n)) puts(" impossible");
       else
       {
           for(i=0;i<n;i++)
           if(get[i]==2)
           {
               dfs2(i);
           }
           for(i=0;i<n;i++)
           if(get[i]==3) printf(" %d",i);
           puts("");
       }




   }
    return 0;

}
