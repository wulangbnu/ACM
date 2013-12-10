#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> s;
void simple(ll &m,ll &n){
    if(m==0||n==0) return;
    ll d=__gcd(m,n);
    m/=d; n/=d;
}
void sub(ll m,ll n,ll x,ll &a,ll &b){
    a=m*x-n;
    b=n*x;
    simple(a,b);
}
bool check(ll m,ll n,ll mid){
    ll a,b;
    sub(m,n,mid,a,b);
    return a==0||b<1000000;
}
void doit(ll m,ll n){

    if(m==0) return;
    ll x=(n+m-1)/m , y=n, a,b;
    if(!check(m,n,x)){
        while(x<y){
            ll mid=(x+y)>>1;
            if(check(m,n,mid)) y=mid;
            else x=mid+1;
        }
    }
    s.push_back(x);
    sub(m,n,x,a,b);
    doit(a,b);
}
int main(){
    freopen("in.2.cpp","r",stdin);
    ll m,n;
    while(scanf("%lld%lld",&m,&n)&&m+n){
        s.clear();
        simple(m,n);
        doit(m,n);
        for(int i=0;i<s.size();i++)
        printf("%lld%c",s[i],i==s.size()-1?'\n':' ');
    }
    return 0;
}
