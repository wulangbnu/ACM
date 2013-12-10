#include<cstdio>
#include<cmath>
int main()
{
    int T,cas=1;
    double r1,r2,h,p;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        double a=(r1-r2)/h,b=r2;
        double ans=a*a/3.0*p*p*p+b*b*p+a*b*p*p;
        printf("Case %d: %.8f\n",cas++,acos(-1.0)*ans);
    }
    return 0;
}
