#include<cstdio>
#include<cmath>
const double P=4-acos(-1.0);
int main()
{
    int T,cas=1;
    double r;
    scanf("%d",&T);
    while(T--){
        scanf("%lf",&r);
        printf("Case %d: %.2f\n",cas++,P*r*r);
    }
    return 0;
}
