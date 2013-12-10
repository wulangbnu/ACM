#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000000
#define N 505
#define M 16005
int pre[N],ans[N];
struct Edge
{
    int a,b,v;
    bool operator < (const Edge tt) const
    {
        return v<tt.v;
    }
}e[M];
int find(int v)
{
    return pre[v]==v?v:pre[v]=find(pre[v]);
}
int main()
{
    freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,t;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d:\n",cas++);

        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
           pre[i]=i;
           ans[i]=INF;

        }

        for(i=0;i<m;i++)
        scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].v);
        sort(e,e+m);
        scanf("%d",&t);
        for(j=i=0;i<m;i++)
        {
            int v1=find(e[i].a),v2=find(e[i].b);
            if(v1!=v2)
            {
               pre[v1]=v2;
               j++;
            }
            for(k=0;k<n;k++)
            if(find(k)==find(t)) ans[k]=min(ans[k],e[i].v);
            if(j>=n-1) break;
        }
        ans[t]=0;
        for(i=0;i<n;i++)
        {
            if(ans[i]<INF) printf("%d\n",ans[i]);
            else puts("Impossible");
        }
    }
    return 0;
}
