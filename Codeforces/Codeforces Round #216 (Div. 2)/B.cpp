#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000+10;
int a[N];
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    int n,k,l,r,sall,sk;
    while(cin>>n>>k>>l>>r>>sall>>sk){
        memset(a,0,sizeof(a));
        int x=sk/k;
        for(int i=1;i<=k;i++) a[i]+=x;
        x=sk%k;
        for(int i=1;i<=x;i++) a[i]+=1;

        if(k<n){
            x=(sall-sk)/(n-k);
            for(int i=k+1;i<=n;i++) a[i]+=x;
            x=(sall-sk)%(n-k);
            for(int i=1;i<=x;i++)   a[k+i]+=1;
        }

        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');

    }
    return 0;
}
