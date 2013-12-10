#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 55
#define INF 0x7fffffff
int a[N],b[N];
int g[N][N],lx[N],ly[N],slack[N];
int my[N],na,nb;
bool getx[N],gety[N];
bool dfs(int x)
{
    getx[x]=true;
    for(int i=0;i<nb;i++)
    {
        if(gety[i]) continue;
        int tmp=lx[x]+ly[i]-g[x][i];
        if(tmp==0)
        {
            gety[i]=true;
            if(my[i]==-1||dfs(my[i]))
            {
                my[i]=x;
                return true;
            }
        }
        else if(tmp<slack[i])
        slack[i]=tmp;
    }
    return false;
}
int KM(int n,int m)
{
    int i,j;
    na=n, nb=m;
    for(i=0;i<na;i++)
    {
        lx[i]=-INF;
        ly[i]=0;
        my[i]=-1;
    }
    for(i=0;i<na;i++)
    for(j=0;j<nb;j++)
    lx[i]=max(lx[i],g[i][j]);

    for(i=0;i<na;i++)
    {
        for(j=0;j<nb;j++)
        slack[j]=INF;
        while(1)
        {
            memset(getx,false,sizeof(getx));
            memset(gety,false,sizeof(gety));
            if(dfs(i)) break;
            int d=INF;
            for(j=0;j<nb;j++)
            {
                if(!gety[j]&&slack[j]<d)
                d=slack[j];
            }
            for(j=0;j<na;j++)
            {
                if(getx[j]) lx[j]-=d;
                if(gety[j]) ly[j]+=d;
                else  slack[j]-=d;
            }

        }
    }
    int ans=0;
    for(i=0;i<na;i++)
    ans+=lx[i]+ly[i];
    return ans;

}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",a+i);
        for(i=0;i<n;i++)
        scanf("%d",b+i);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
           if(a[i]>b[j]) g[i][j]=2;
           else if(a[i]==b[j]) g[i][j]=1;
           else g[i][j]=0;

        }
        printf("%d\n",KM(n,n));
    }
    return 0;

}
