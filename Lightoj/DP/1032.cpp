#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll solve(ll x){
    ll ret=0;
    for(int i=1;i<31;i++){
        ret+=x/(1ll<<(i+1))*(1ll<<(i-1));
        ret+=max(x%(1ll<<(i+1))-((1ll<<(i+1))-(1ll<<(i-1))),0ll);
    }
    return ret;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    ll n;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cas++,solve(n+1));
    }
    return 0;
}
