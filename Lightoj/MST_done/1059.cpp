#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10005
#define M 200005
int pre[N];
int find(int v)
{
    return pre[v]==v?v:pre[v]=find(pre[v]);
}
struct Edge
{
    int a,b,v;
    bool operator <(const Edge tt) const
    {
      if(v!=tt.v)  return v<tt.v;
      return a<tt.a;
    }
}e[M];
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,A,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);

        scanf("%d %d %d",&n,&m,&A);
        for(i=0;i<=n;i++) pre[i]=i;
        for(i=0;i<m;i++)
        scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].v);
        for(i=1;i<=n;i++)
        {
            e[m].a=0;
            e[m].b=i;
            e[m++].v=A;
        }
        sort(e,e+m);
        int ans1=0,ans2=0;
        for(j=i=0;i<m;i++)
        {
            int v1=find(e[i].a),v2=find(e[i].b);
            if(v1!=v2)
            {
                pre[v1]=v2;
                j++;
                ans1+=e[i].v;
                if(e[i].a==0) ans2++;
            }
          if(j>=n+1) break;
        }

        printf("%d %d\n",ans1,ans2);





    }




  return 0;

}
