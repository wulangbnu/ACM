#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD=1000007;
ll sum[MOD],cnt[MOD];
int main(){
    //freopen("in.cpp","r",stdin);
    ios::sync_with_stdio(false);
    ll T, k, c, n , a0, i,cas=1;
    cin>>T;
    while(T--){
        cin>>k>>c>>n>>a0;
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        sum[a0]+=a0;
        cnt[a0]++;
        for(i=1;i<n;i++){
            a0=(k*a0+c)%MOD;
            sum[a0]+=a0;
            cnt[a0]++;
        }

        for(i=1;i<MOD;i++){
            sum[i]+=sum[i-1];
            cnt[i]+=cnt[i-1];
        }

        ll ans=0;
        for(i=0;i<MOD;i++){
            if(cnt[i]==cnt[i-1]) continue;
            ans+=(cnt[i-1]*i-sum[i-1])*(cnt[i]-cnt[i-1]);
            ans+=( sum[MOD]-sum[i]-(cnt[MOD]-cnt[i])*i )*(cnt[i]-cnt[i-1]);
        }
        cout<<"Case "<<cas++<<": "<<ans/2<<endl;
    }
    return 0;
}
