#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
    //freopen("in.cpp","r",stdin);
    ll n;
    while(cin>>n){
        ll x=sqrt(n)+(1e-8), y;
        for(y=x;;y++) if(x*y>=n) break;
        ll ans=min((x+y)*2,(x+1)*4);
        cout<<ans<<endl;
    }
    return 0;
}
