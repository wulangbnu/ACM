#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=1000000+10;
struct Point{
    ll d,t;
    bool operator <(const Point &tt) const{
//        ll x=t-d, y=tt.t-tt.d;
//        if(x!=y) return x<y;
//        return d<tt.d;
          if(t!=tt.t) return t<tt.t;
          return d>tt.d;
    }
}p[N];
ll n;
bool check(ll mid){
    for(int i=0;i<n;i++){
        if(mid>p[i].t-p[i].d) return false;
        mid=mid+p[i].d;
    }
    return true;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%lld",&n)+1){
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&p[i].d,&p[i].t);
            p[i].t++;
        }
        sort(p,p+n);
        ll x=0, y=1000000000+10;
        while(x<y){
            ll mid=(x+y+1)>>1;
            if(check(mid)) x=mid;
            else y=mid-1;
        }
        printf("%lld\n",x-1);
    }
    return 0;
}
