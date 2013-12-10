#include<cstdio>
#include<algorithm>
using namespace std;
#define N 105
#define M 12005
int pre[N];
struct Edge
{
    int a,b,v;
    bool operator <(const Edge tt) const
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
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);

        scanf("%d",&n);
        for(i=0;i<=n;i++) pre[i]=i;

        m=0;
        while(1)
        {
            scanf("%d %d %d",&e[m].a,&e[m].b,&e[m].v);
            if(e[m].a==0&&e[m].b==0&&e[m].v==0) break;
            m++;
        }
        sort(e,e+m);
        int ans=0;
        for(i=j=0;i<m;i++)
        {
            int v1=find(e[i].a), v2=find(e[i].b);

            if(v1!=v2)
            {
                pre[v1]=v2;
                ans+=e[i].v;
                j++;
            }
            if(j>=n) break;
        }



        for(i=0;i<=n;i++) pre[i]=i;
        for(j=0,i=m-1;i>=0;i--)
        {
            int v1=find(e[i].a),v2=find(e[i].b);
            if(v1!=v2)
            {
                pre[v1]=v2;
                ans+=e[i].v;
                j++;
            }
            if(j>=n) break;
        }

        if(ans%2) printf("%d/2\n",ans);
        else printf("%d\n",ans/2);

    }
    return 0;
}
