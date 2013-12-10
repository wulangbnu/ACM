#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=100000+10;
ll a[N],n;
ll g[N][20],ans;
inline void init(){
    for(ll i=0;i<n;i++) g[i][0]=a[i];
    for(ll j=1;(1<<j)-1<n;j++)
    for(ll i=0;i+(1<<j)-1<n;i++){
        g[i][j]=__gcd(g[i][j-1],g[i+(1<<(j-1))][j-1]);
    }
}
inline ll F(ll x,ll y){
    ll k=log2(y-x+1.0)+(1e-8);
    return __gcd(g[x][k],g[y-(1<<k)+1][k]);
}
void doit(ll left,ll now, ll v){
    if(v*(n-left)<=ans) return;
    ll x=now,y=n-1;
    while(x<y){
        ll mid=(x+y+1)>>1;
        if(F(left,mid)==v) x=mid;
        else y=mid-1;
    }
    ans=max(ans,v*(x-left+1));
    if(++x<n) doit(left,x,__gcd(v,a[x]));
}
void inline get(ll &x){
    char ch=0;
    x=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}
int main(){
    
    ll T;
    get(T);
    while(T--){
        get(n);
        for(ll i=0;i<n;i++) get(a[i]);
        init();

        ans=n;
        for(ll i=0;i<n;i++){
//            cout<<"~~~ "<<i<< "  "<< a[i] <<endl;
            doit(i,i,a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
