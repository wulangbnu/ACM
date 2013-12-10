#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 100005
int rmq[N][20];
void RMQ(int n)
{
    for(int j=1;(1<<j)<=n;j++)
    for(int i=0;i+(1<<j)-1<n;i++){
        rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
    }
}
int getint()
{
    char c=0;
    int re=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        re=re*10+c-'0';
        c=getchar();
    }
    return re;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    T=getint();
    while(T--)
    {
        printf("Case %d:\n",cas++);
        n=getint();
        m=getint();
        for(i=0;i<n;i++){
            j=getint();
            rmq[i][0]=j;
        }
        RMQ(n);
        while(m--){
            i=getint();
            j=getint();
            i--;
            j--;
            k=log(j-i+1.0)/log(2.0);
            printf("%d\n",min(rmq[i][k],rmq[j-(1<<k)+1][k]));
        }
    }
    return 0;
}
