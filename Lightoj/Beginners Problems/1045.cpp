#include<cstdio>
#include<cmath>
const double PI=acos(-1.0);
int main()
{
    int T,cas=1,n,m,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        if(n==0) ans=1;
        else ans=(n*log(n)-n+0.5*log(2*n*PI))/log(m)+(1e-8)+1;
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
