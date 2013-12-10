#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int N=100+10;
const ll INF=(1ll<<60);
int n,d,a[N];
vector<ll> s;
ll dp[N][2*N*N];
void doit(int a[]){
    s.clear();
    for(ll i=1;i<=n;i++){
        s.push_back(a[i]);
        for(ll j=1;j<=n;j++){
            s.push_back(a[i]-d*j);
            s.push_back(a[i]+d*j);
        }
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        doit(a);

        int m=s.size();
        for(int j=0;j<m;j++) dp[1][j]=(s[j]==a[1])?0:INF;

        for(int i=2;i<=n;i++){
            int x=0;
            for(int j=0;j<m;j++){
                dp[i][j]=INF;
                while(x<m&&s[x]+d<s[j])  x++;
                while(x+1<m&&s[x+1]<=s[j]+d&&dp[i-1][x+1]<=dp[i-1][x]) x++;
                dp[i][j]=min(dp[i][j],dp[i-1][x]+abs(s[j]-a[i]));
            }
        }

        ll ans;
        for(int j=0;j<m;j++)
        if(s[j]==a[n]) ans=dp[n][j];
        if(ans<INF) cout<<ans<<endl;
        else puts("impossible");
    }
    return 0;
}
