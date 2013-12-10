#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N=1000000+10;
const double EPS=1e-8;
double a[N];
int n,m,r;
bool check(double x,double y){
    return  (y-x)*(y-x)+1<r*r+EPS;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d",&n,&m,&r)+1){
        for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
        int now=1,x,y;
        double ans=0.0;
        for(int i=1;i<=m;i++){
            double p;
            scanf("%lf",&p);
            if(check(a[now],p)) continue;
            if(a[now]<p){
                x=now;
                y=lower_bound(a+1,a+1+n,p)-a;
                if(y>n||!check(a[y],p)) y--;
                while(x<y){
                    int mid=(x+y)>>1;
                    if(check(a[mid],p)) y=mid;
                    else x=mid+1;
                }
                ans+=a[x]-a[now];
                now=x;

            }else{
                y=now;
                x=lower_bound(a+1,a+1+n,p)-a;
                if(!check(a[x],p)) x--;
                while(x<y){
                    int mid=(x+y+1)>>1;
                    if(check(a[mid],p)) x=mid;
                    else y=mid-1;
                }
                ans+=a[now]-a[x];
                now=x;
            }
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
