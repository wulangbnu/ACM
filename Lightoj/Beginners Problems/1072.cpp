#include<cstdio>
#include<cmath>
const double PI=acos(-1.0);
int main()
{
    int T,cas=1,n;
    double R,r;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%d",&R,&n);
        r=R/(1.0/sin(PI/n)+1.0);
        printf("Case %d: %.8f\n",cas++,r);
    }
    return 0;
}
