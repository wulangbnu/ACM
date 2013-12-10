#include<cstdio>
#include<algorithm>
using namespace std;
#define N 55
int pre[N];
struct Edge
{
    int a,b,v;
    bool operator <(const Edge tt) const
    {
        return v<tt.v;
    }
}e[N*N];
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
        int sum=0;

        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&k);
            if(k)
            {
                sum+=k;
                e[m].a=i;
                e[m].b=j;
                e[m++].v=k;
            }
        }
        sort(e,e+m);
        for(j=i=0;i<m;i++)
        {
            int v1=find(e[i].a),v2=find(e[i].b);
            if(v1!=v2)
            {
                pre[v1]=v2;
                sum-=e[i].v;
                j++;
            }
            if(j>=n-1) break;
        }

        if(j<n-1) puts("-1");
        else printf("%d\n",sum);


    }


     return 0;


}
