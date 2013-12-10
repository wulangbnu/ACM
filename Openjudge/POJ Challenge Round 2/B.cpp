#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll t,a[2],c[2],d;
bool check(ll mid){
    return (mid-1)/d+1+mid<=t;
}
ll doit(){
    ll ret=((t-1)/c[0]+1)*a[0];

    ll x=0, y=t+10;
    while(x<y){
        ll mid=(x+y+1)>>1;
        if(check(mid)) x=mid;
        else y=mid-1;
    }
    cout<<ret<<endl;
    if(x<=t&&x)
    ret+=((x-1)/c[1]+1)*a[1];
    cout<<x<<" "<<ret<<endl;
    return ret;
}
int main(){
    freopen("in.cpp","r",stdin);
    while(cin>>t){

        for(int i=0;i<2;i++) cin>>a[i]>>c[i];

        d=c[0]/__gcd(c[0],c[1])*c[1];
        ll ans=doit();

        swap(a[0],a[1]);
        swap(c[0],c[1]);
        ans=max(ans,doit());

        cout<<ans<<endl;
    }
    return 0;
}
