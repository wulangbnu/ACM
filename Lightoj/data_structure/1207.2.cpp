#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200000+10;
int next[N],a[N],b[N];
int find(int x)
{
    return next[x]==x?x:next[x]=find(next[x]);
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<=2*n+5;i++)
        next[i]=i;
        for(i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
        int ans=0;
        for(i=n;i>=1;i--){
            if(find(a[i])-1>=b[i]) continue;
            ans++;
            if(next[b[i]]==b[i])  next[b[i]]=b[i]+1;
            for(j=find(a[i]);j<b[i];j=find(j+1)){
                next[j]=find(b[i]);
            }
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
