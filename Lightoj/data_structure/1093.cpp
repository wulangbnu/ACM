#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100000+10;
int mind[N][20],maxd[N][20];
void RMQ(int n)
{
    for(int j=1;(1<<j)<=n;j++)
    for(int i=0;i+(1<<j)-1<n;i++){
        mind[i][j]=min(mind[i][j-1],mind[i+(1<<(j-1))][j-1]);
        maxd[i][j]=max(maxd[i][j-1],maxd[i+(1<<(j-1))][j-1]);
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&j);
            mind[i][0]=j;
            maxd[i][0]=j;
        }
        RMQ(n);
        int ans=0;
        for(i=0;i+m-1<n;i++){
            int x=i,y=i+m-1;
            k=log(y-x+1.0)/log(2.0);
            int ans1=max(maxd[x][k],maxd[y-(1<<k)+1][k]);
            int ans2=min(mind[x][k],mind[y-(1<<k)+1][k]);
            ans=max(ans,ans1-ans2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
