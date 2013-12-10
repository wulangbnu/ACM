#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105
bool g[N][N];
bool get[N];
int c[N][N];
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(g,false,sizeof(g));
        memset(get,false,sizeof(get));
        memset(c,0,sizeof(c));
        printf("Case %d: ",cas++);

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&j,&k);
            g[j][k]=g[k][j]=true;
            scanf("%d",&c[k][j]);
        }
        int s=1,ans=0;
        for(k=0;k<n-1;k++)
        {
            get[s]=true;
            for(i=1;i<=n;i++)
            if(g[s][i]&&!get[i]) break;
            ans+=c[s][i];
            s=i;
        }
        ans+=c[s][1];
        int tmp=0;
        s=1;
        memset(get,false,sizeof(get));
        for(k=0;k<n-1;k++)
        {
            get[s]=true;
            for(i=n;i>0;i--)
            if(g[s][i]&&!get[i]) break;
            tmp+=c[s][i];
            s=i;
        }
        tmp+=c[s][1];

        printf("%d\n",min(ans,tmp));
    }
    return 0;
}
