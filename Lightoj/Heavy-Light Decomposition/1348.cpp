#include<cstdio>
#include<cstring>
#define N 30005
#include<algorithm>
using namespace std;
int in[N],p[N],a[N];
int get[N],st;
int u[2*N],v[2*N],first[N],next[2*N];
void dfs(int i)
{
    if(get[i]) return;
    get[i]=1;
    p[i]=++st;
    for(int e=first[i];e+1;e=next[e])
    dfs(v[e]);
}
void add(int x,int val)
{
    for(int i=x;i<N;i+=i&(-i))
    v[i]+=val;
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=i&(-i))
    ans+=v[i];
    return ans;
}
int main()
{
    freopen("in.cpp","r",stdin);
    int T,n,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d:\n",cas++);

        memset(p,0,sizeof(p));
        memset(in,0,sizeof(in));
        memset(first,-1,sizeof(first));
        memset(get,0,sizeof(get));
        st=0;

        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<2*(n-1);i+=2)
        {
            scanf("%d %d",&j,&k);
            u[i]=j,v[i]=k;
            next[i]=first[j];
            first[j]=i;
            u[i+1]=k,v[i+1]=j;
            next[i+1]=first[k];
            first[k]=i+1;
            in[j]++;
            in[k]++;
        }
        for(i=0;i<n;i++)
        if(in[i]==1) dfs(i);

        for(i=0;i<n;i++) printf("***%d %d\n",i,p[i]);

        memset(v,0,sizeof(v));

        for(i=0;i<n;i++)
        add(p[i],a[i]);
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d %d",&k,&i,&j);
            if(k==0)
            {
               if(p[i]<p[j]) swap(p[i],p[j]);
               printf("%d\n",sum(p[j])-sum(p[i]-1));
            }
            else
            {
                k=sum(p[i])-sum(p[i]-1);
                add(p[i],j-k);
            }

        }


    }
    return 0;
}
