#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 205
bool e[N][N];
int w[N];
void euler(int u)
{
    for(int v=1;v<=n;v++)
    if(e[u][v])
    {
        e[u][v]=false;
        euler(v);
    }
   ans[cnt++]=u;
}
int main()
{
    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
       printf("Case %d: ",cas++);
       memset(e,false,sizeof(e));
       scanf("%d %d",&n,&m);
       for(i=1;i<=n;i++)
       scanf("%d",&w[i]);
       while(m--)
       {
           scanf("%d %d",&i,&j);
           e[i][j]=true;
       }

    }
}
