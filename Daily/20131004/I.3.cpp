#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
vector<ll> s;
map<ll,ll> mp[1000000+1];
void simple(ll &m,ll &n){
    ll d=__gcd(m,n);
    m/=d; n/=d;
}
void sub(ll m,ll n,ll x,ll &a,ll &b){
    a=m*x-n;
    b=n*x;
    simple(a,b);
}
bool dfs(ll m,ll n,ll pre){
    if(n<100000&&mp[n].count(m)){
        ll x=mp[n][m],a,b;
        sub(m,n,x,a,b);
        dfs(a,b,x);
        s.push_back(x);
        return true;
    }
    if(m==0) return true;
    ll x=(n+m-1)/m, a,b;
    x=max(x,pre);
    for(;x<=n&&x<1000000;x++){
        sub(m,n,x,a,b);
        if(dfs(a,b,x)){
            mp[n][m]=x;
            s.push_back(x);
            return true;
        }
    }
    return false;
}
int main(){
    freopen("in.cpp","r",stdin);
    ll m,n;
    while(scanf("%lld%lld",&m,&n)&&m+n){
        cout<<"~~"<<m<<" "<<n<<endl;
        s.clear();
        simple(m,n);
        dfs(m,n,2);
        for(int i=s.size()-1;i>=0;i--)
        printf("%lld%c",s[i],i==0?'\n':' ');
    }
    return 0;
}
