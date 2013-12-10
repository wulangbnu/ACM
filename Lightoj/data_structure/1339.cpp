#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100000+10;
int a[N],rmq[N][20],p[N],first[N];
int tot;
void RMQ()
{
    for(int j=1;(1<<j)<=tot;j++)
    for(int i=0;i+(1<<j)-1<tot;i++)
    rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
int query(int i,int j)
{
    if(i>j) return 0;
    int k=log(j-i+1.0)/log(2.0)+1e-8;
    return max(rmq[i][k],rmq[j-(1<<k)+1][k]);
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k,c,q;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        scanf("%d%d%d",&n,&c,&q);
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<c;i++)
        rmq[i][0]=0;
        tot=0;
        p[1]=tot;
        first[tot]=1;
        rmq[tot][0]++;
        for(i=2;i<=n;i++){
           if(a[i]==a[i-1])  p[i]=tot;
           else {
                p[i]=++tot;
                first[tot]=i;
           }
           rmq[tot][0]++;
        }
        tot++;
        RMQ();
        while(q--){
            scanf("%d%d",&i,&j);
            if(p[i]==p[j]){
                printf("%d\n",j-i+1);
                continue;
            }
            int ans=query(p[i]+1,p[j]-1);
            ans=max(ans,first[p[i]+1]-i);
            ans=max(ans,j-first[p[j]]+1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
