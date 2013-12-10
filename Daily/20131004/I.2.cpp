#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> s;
void simple(ll &m,ll &n){
    ll d=__gcd(m,n);
    m/=d; n/=d;
}
void sub(ll m,ll n,ll x,ll &a,ll &b){
    b=n/__gcd(n,x)*x;
    a=m*(b/n)-(b/x);
    simple(a,b);
}
bool dfs(ll m,ll n,ll pre=2){
    if(n>=2000000) return false;
    if(m==0) return true;
    ll x=(n+m-1)/m,a,b;
    x=max(x,pre);
    for(;x<=n&&x<1000000;x++){
        sub(m,n,x,a,b);
        if(dfs(a,b,x)){
            s.push_back(x);
            return true;
        }
    }
    return false;
}
int main(){
    freopen("in.cpp","r",stdin);
    //freopen("ans.txt","w",stdout);

    ll m,n;
    while(scanf("%lld%lld",&m,&n)&&m+n){
        s.clear();
        simple(m,n);
        dfs(m,n);
        for(int i=s.size()-1;i>=0;i--)
        printf("%lld%c",s[i],i==0?'\n':' ');
    }
    return 0;
}
