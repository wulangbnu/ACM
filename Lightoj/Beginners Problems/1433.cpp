#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double EPS=1e-8;
double x[3],y[3],r;
double doit(){
    x[1]-=x[0]; y[1]-=y[0];
    x[2]-=x[0]; y[2]-=y[0];
    double ret=(x[1]*x[2]+y[1]*y[2])/r/r;
    ret=min(ret,1.0); ret=max(ret,-1.0);
    return acos(ret);
}
int main(){
   //freopen("in.cpp","r",stdin);
    int T,cas=1,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        for(i=0;i<3;i++)
        scanf("%lf%lf",&x[i],&y[i]);
        r=hypot(x[0]-x[1],y[0]-y[1]);
        if(fabs(r)<EPS){
            puts("0.000000000");
            continue;
        }
        double ans=doit()*r;
        printf("%.8f\n",ans);
    }
    return 0;
}
