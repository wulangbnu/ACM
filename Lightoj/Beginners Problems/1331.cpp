#include<cstdio>
#include<cmath>
double r1,r2,r3;
double doit(){
    return sqrt((r1+r2+r3)*r1*r2*r3);
}
double solve(double a,double b,double c,double r){
    return acos((b*b+c*c-a*a)/(2*b*c))*r*r/2.0;
}
int main(){

    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        printf("%.9f\n",doit()-solve(r1+r3,r1+r2,r3+r2,r2)-solve(r2+r3,r2+r1,r3+r1,r1)-solve(r1+r2,r1+r3,r2+r3,r3)+(1e-9));
    }
    return 0;
}
