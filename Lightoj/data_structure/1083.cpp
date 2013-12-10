#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 30005
int a[N],pre[N],post[N];
void doit(int a[],int n,int pre[])
{
    for(int i=1;i<=n;i++)
    for(int j=i-1;j>=0;j--){
        if(a[j]>=a[i]) j=pre[j];
        if(a[j]<a[i]){
            pre[i]=j;
            break;
        }
    }
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
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        a[0]=-1;
        doit(a,n,pre);
        for(i=1;2*i<=n;i++)
        swap(a[i],a[n+1-i]);
        doit(a,n,post);
        int ans=0;
        for(i=1;i<=n;i++)
        ans=max(ans,a[i]*(n-post[i]-pre[n+1-i]));
        printf("%d\n",ans);
    }
    return 0;
}
