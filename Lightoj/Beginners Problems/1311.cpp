#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    double v1,v2,v3,a1,a2;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        printf("%.9f %.9f\n",v1*v1/2.0/a1+v2*v2/2.0/a2,v3*max(v1/a1,v2/a2));
    }
    return 0;
}
