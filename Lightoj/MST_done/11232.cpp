#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 205
#define M 6005
struct Edge
{
    int a,b,v;
    bool operator < (const Edge tt) const
    {
        return v<tt.v;
    }
}e[M];
int pre[N];
int f[N];
int find(int v)
{
    return pre[v]==v?v:pre[v]=find(pre[v]);
}
bool check(int n)
{
    for(int i=2;i<=n;i++)
    if(find(i)!=find(1)) return false;
    return true;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {

        printf("Case %d:\n",cas++);
        scanf("%d %d",&n,&m);

        for(i=0;i<=n;i++) pre[i]=i;

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].v);
            pre[find(e[i].a)]=find(e[i].b);
            if(check(n)) break;
            else puts("-1");
        }
        if(i>=m) continue;
        int t=i+1;
        sort(e,e+t);
        for(i=0;i<=n;i++) pre[i]=i;
        int ans=0;
        memset(f,0,sizeof(f));

        for(j=i=0;i<t;i++)
        {
            int v1=find(e[i].a),v2=find(e[i].b);
            if(v1!=v2)
            {
                pre[v1]=v2;
                ans+=e[i].v;
                j++;
                f[i]=1;
            }
            if(j>=n-1) break;
        }
        printf("%d\n",ans);

        for(j=i=0;i<t;i++)
        if(f[i])
        {
            e[j].a=e[i].a;
            e[j].b=e[i].b;
            e[j++].v=e[i].v;
        }

        for(;t<m;t++)
        {
           scanf("%d %d %d",&e[n-1].a,&e[n-1].b,&e[n-1].v);
           sort(e,e+n);


        for(i=0;i<=n;i++) pre[i]=i;
        ans=0;
        memset(f,0,sizeof(f));

        for(j=i=0;i<n;i++)
        {
            int v1=find(e[i].a),v2=find(e[i].b);
            if(v1!=v2)
            {
                pre[v1]=v2;
                ans+=e[i].v;
                j++;
                f[i]=1;
            }
            if(j>=n-1) break;
        }
        printf("%d\n",ans);

        for(j=i=0;i<n;i++)
        if(f[i])
        {
            e[j].a=e[i].a;
            e[j].b=e[i].b;
            e[j++].v=e[i].v;
        }


        }



    }
    return 0;
}
