#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 20005
#define M 200005
queue<int> q;
int a[N][2];
int get[N],p[N];
int u[M],v[M],first[N],next[M];
void bfs(int i)
{
    if(get[i]) return;
    get[i]=1;
    int t=0;
    q.push(i);
    if(first[i]!=-1) a[i][0]++;

    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(int e=first[s];e!=-1;e=next[e])
        if(!get[v[e]])
        {
            p[v[e]]=p[s]+1;
            a[i][p[v[e]]%2]++;
            q.push(v[e]);
            get[v[e]]=1;
        }
        t=1-t;
    }


}
int main()
{
    //freopen("in.cpp","r",stdin);

  int T,n,m,i,j,k;
  int cas=1;
  scanf("%d",&T);
  while(T--)
  {
      printf("Case %d: ",cas++);
      memset(first,-1,sizeof(first));
      memset(get,0,sizeof(get));
      memset(p,0,sizeof(p));
      for(i=0;i<N;i++)
      a[i][0]=a[i][1]=0;
      while(!q.empty()) q.pop();

      scanf("%d",&m);
      m*=2;
      for(i=0;i<m;i+=2)
      {
          scanf("%d %d",&u[i],&v[i]);
          next[i]=first[u[i]];
          first[u[i]]=i;
          v[i+1]=u[i],u[i+1]=v[i];
          next[i+1]=first[u[i+1]];
          first[u[i+1]]=i+1;
      }
       for(i=1;i<N;i++)
       if(!get[i]) bfs(i);

       for(j=0,i=1;i<N;i++)
       j+=max(a[i][0],a[i][1]);
       printf("%d\n",j);

  }
  return 0;
}
