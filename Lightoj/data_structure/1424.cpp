#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2000+10;
int a[N][N];
int main()
{
    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]+a[i-1][j-1];
        }

    }
    return 0;
}
