#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100+10;
struct Point{
    int x,d,id;
    bool operator <(const Point &tt) const{
        return x<tt.x;
    }
}p[N];
int n,m,a[N];
bool check(int t){
    for(int i=0;i<n;i++) a[i]=p[i].x+t*p[i].d;
    sort(a,a+n);
    if(a[m]<=0||a[m]>=100) return true;
    return false;
}
void solve(){
    int x, y=200+10;
    while(x<y){
        int mid=(x+y)>>1;
        if(check(mid)) y=mid;
        else x=mid+1;
    }
    if(x>200) puts("Cannot fall!");
    else printf("%d\n",x);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].d);
            p[i].id=i;
            if(p[i].d==0) m=i;
        }
        sort(p,p+n);
        for(int i=0;i<n;i++){
            if(p[i].id==m){
                m=i;break;
            }
        }

        solve();
    }
    return 0;
}
