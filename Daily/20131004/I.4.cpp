#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> s;
void simple(ll &a,ll &b){
    ll d=__gcd(a,b);
    a/=d; b/=d;
}
void sub(ll m,ll n,ll x,ll &a,ll &b){
    a=m*x-n;
    b=n*x;
    simple(a,b);
}
bool dfs(ll m,ll n,ll pre=2){
    if(n>=1000000) return false;
    if(m==0) return true;
    for(ll x=max((n+m-1)/m,pre),a,b;x<1000000;x++){
        sub(m,n,x,a,b);
        if(dfs(a,b,x)){
            s.push_back(x);
            return true;
        }
    }
    return false;
}
int main(){
    //freopen("in.cpp","r",stdin);
    ll m,n;
    while(scanf("%lld%lld",&m,&n)&&n+m){
        simple(m,n);
        s.clear();
        dfs(m,n);
        for(int i=s.size()-1;i>=0;i--)
        printf("%lld%c",s[i],i==0?'\n':' ');
    }
    return 0;
}
