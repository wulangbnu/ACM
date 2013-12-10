#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const ll N=10000+10;
const double INF=1e30;
const double EPS=1e-8;
ll n,d,l,w,S,T;
struct Point{
    ll s,t;
    bool operator <(const Point &tt) const{
        //return s/t<tt.s/tt.t;
        return s*tt.t<tt.s*t;
    }
}p[N];
int sgn(double x){
    return x<-EPS?-1:x>EPS;
}
double doit(ll i,ll j){
    if(p[i].s==p[j].s) return INF;
    double x=((w-S*1.0)/l-p[j].s)/(p[i].s-p[j].s);
    if(sgn(x)<=0||sgn(x-1.0)>=0) return INF;
    //printf("~~%lld %lld %lld  %f\n",p[i].s,s[j],l,x);
    return T+l*x*p[i].t+l*(1.0-x)*p[j].t;
}
int main(){
    //freopen("in.cpp","r",stdin);
    ll _;
    scanf("%lld",&_);
    while(_--){
        scanf("%lld%lld%lld%lld",&n,&d,&l,&w);
        for(ll i=1;i<=n;i++) scanf("%lld%lld",&p[i].s,&p[i].t);
        if(n*d>l){
            puts("No solution");
            continue;
        }
        S=0,T=0;
        for(ll i=1;i<=n;i++) S+=p[i].s*d,T+=p[i].t*d;
        l-=n*d;
        //printf("~~%lld\n",l);

        double ans=INF;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(S+l*p[i].s<=w){
                ans=min(ans,T+l*p[i].t*1.0);
                flag=1;
            }
        }
        if(flag==0){
            puts("No solution");
            continue;
        }

//        sort(p+1,p+1+n);
//        for(ll i=1;i<n;i++){
//            ans=min(ans,doit(i,i+1));
//        }
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            ans=min(ans,doit(i,j));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
