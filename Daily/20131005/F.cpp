#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=500005;
typedef __int64 ll;

int n;
ll a[maxn],s[maxn];
ll c[maxn];

int main() {
    //freopen("in.cpp","r",stdin);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%I64d",&a[i]);
        for(int i=1; i<=n; i++)s[i]=s[i-1]+a[i];
        c[n]=s[n];
        for(int i=n-1; i>=1; i--)
            c[i]=min(c[i+1],s[i]);
        int ret=0;
        if(c[1]<=0)ret++;
        if(n>1) {
            ll l=s[n];
            for(int i=2; i<=n; i++) {
                ll r=c[i]-s[i-1];
                if(l<=0||r<=0)ret++;
                l=min(s[n],l-(s[i]-s[i-1]));
            }
        }
        printf("Case %d: %d\n",++ncase,n-ret);
    }
    return 0;
}
