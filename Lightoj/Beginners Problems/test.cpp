#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const ll INF=1e18;
int main()
{
    ll ans=1,sum=1;
    for(int i=1;i<=20;i++){
        sum+=ans;
        ans*=i;
        if(ans<INF) cout<<i<<" : "<<ans<<"  "<<sum-1ll<<endl;
    }

}
