#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=4000;

ll n;
ll aa[maxn+5];

void init() {
    for(int i=1; i<=maxn; i++)
        aa[i]=(ll)i*i*i;
}

int bs(ll x) {
    int l=0,r=maxn;
    while(l<=r) {
        int m=(l+r)/2;
        if(aa[m]==x)return m;
        else if(aa[m]<x)l=m+1;
        else r=m-1;
    }
    return -1;
}

bool solve() {
    int maxx=4001;
    ll a,c,b;
    for(int i=1; i<=2000; i++)
        for(int j=i; j<=4000; j++) {
            if(i+j>=maxn)break;
            ll tt=aa[i]+aa[j];
            if(tt%n!=0)continue;
            tt/=n;
            int pos=bs(tt);
            if(pos==-1)continue;
            int sum=i+j+pos+pos;
            if(sum>=maxn)continue;
            if(sum<maxx) {
                maxx=sum;
                a=j,c=i,b=pos;
                printf("(%lld/%lld)^3 + (%lld/%lld)^3 = %lld\n",a,b,c,b,n);
                return 1;
            }
        }
    if(maxx==4001)return 0;
    printf("(%lld/%lld)^3 + (%lld/%lld)^3 = %lld\n",a,b,c,b,n);
    return 1;
}

int main() {
    init();
   // freopen("in.cpp","r",stdin);
    while(scanf("%lld",&n)&&n) {
        if(!solve())printf("No value.\n");
    }
    return 0;
}
