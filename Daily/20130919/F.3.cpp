#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const ll N=100000+10;
ll n,s,w,q;
ll a[N],b[N],p[N];
ll qq[N];
void init(){
    ll g = s;
    for(ll i=0; i<n; i++) {
          a[i] = (g/7) % 10;
          if( g%2 == 0 ) { g = (g/2); }
          else           { g = (g/2) ^ w; }
    }
    p[0]=1;
    for(ll i=1;i<=n;i++) p[i]=10*p[i-1]%q;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(cin>>n>>s>>w>>q){
        if(n==0&&s==0&&w==0&&q==0) break;
        init();
        for(ll k=0,i=n-1;i>=0;i--){
            k=(a[i]*p[n-1-i]+k)%q;
            b[i]=k;
        }

        for(ll i=0;i<n;i++) qq[i]=b[i];
        qq[n]=0;
        sort(qq,qq+n+1);
        ll cnt=unique(qq,qq+n+1)-qq;

        for(ll i=0;i<n;i++)
        b[i]=lower_bound(qq,qq+cnt,b[i])-qq;
        memset(p,0,sizeof(p));
        for(ll i=0;i<n;i++)
        if(a[i]>0) p[b[i]]++;

        ll ans=0;
        for(ll k=0,i=n-1;i>=0;i--){
            ans+=p[k];
            k=b[i];
            if(a[i]>0) p[k]--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
