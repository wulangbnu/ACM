#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
#define N 405
#define M 6005
#define INF 500000000
queue<pii> q;
int pre[N];
int u[N],v[N],w[N],first[N],next[N];
int find(int  v)
{
    return pre[v]==v?v:pre[v]=find(pre[v]);
}
struct Edge
{
    int a,b,v;
    bool operator < (const Edge tt) const
    {
        return v<tt.v;
    }
}e[M];
bool check(int n)
{
    for(int i=2;i<=n;i++)
    if(find(i)!=find(1)) return false;
    return true;
}
int main()
{

   freopen("in.pp","r",stdin);

   int  T,n,W,m,i,j,k;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d:\n",cas++);
       scanf("%d %d",&n,&W);
       for(i=0;i<=n;i++) pre[i]=i;

        m=0;
       for(k=0;k<W;k++)
       {
           scanf("%d %d %d",&e[m].a,&e[m].b,&e[m].v);
           pre[find(e[m].a)]=find(e[m].b);
           m++;
           if(check(n)) break;
           puts("-1");
       }
       if(k>=W) continue;

       for(i=0;i<=n;i++) pre[i]=i;
       sort(e,e+m);
       int ans=0,cnt=1;
       memset(first,-1,sizeof(first));
       for(j=i=0;i<m;i++)
       {
           int v1=find(e[i].a),v2=find(e[i].b);
           if(v1!=v2)
           {
              pre[v1]=v2;
              ans+=e[i].v;
               j++;

               u[cnt]=e[i].a,v[cnt]=e[i].b;
               next[cnt]=first[u[cnt]];
               first[u[cnt]]=cnt;
               cnt++;
               u[cnt]=e[i].b, v[cnt]=e[i].a;
               next[cnt]=first[u[cnt]];
               first[u[cnt]]=cnt;
               cnt++;


           }
          if(j>=n-1) break;
       }
       printf("%d\n",ans);

       for(;k<W;k++)
       {
           int a,b,c;
           scanf("%d %d %d",&a,&b,&c);

           while(!q.empty()) q.pop();
           memset(pre,0,sizeof(pre));

           q.push(make_pair(a,0));
           pre[a]=1;
           int tmp;
           int flag=0;
           while(!q.empty())
           {
               pii p=q.front();
               q.pop();
               for(int e=first[p.first];e!=-1;e=next[e])
               {
                   if(v[e]==b)
                   {
                      if(w[p.second]>w[e]) tmp=p.second;
                      else tmp=e;
                      flag=1;
                   }
                   if(flag) break;
                   if(w[e]>w[p.second]) q.push(make_pair(v[e],e));
                   else q.push(make_pair(v[e],p.second));
                   pre[v[e]]=1;
               }
               if(flag) break;

            }
            if(w[tmp]>c)
            {
               ans-=w[tmp]-c;
               for(i=1;i<cnt;i++)
               if(u[i]==v[tmp]&&v[i]==u[tmp]) break;
               u[i]=b,v[i]=a,w[i]=c;
               u[tmp]=a,v[tmp]=b,w[tmp]=c;

            }
            printf("%d\n",ans);






       }





   }

    return 0;




}
