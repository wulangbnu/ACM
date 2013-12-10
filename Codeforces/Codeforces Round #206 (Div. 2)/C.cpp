#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
int n,l,r,ql,qr,w[N],sum[N];
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr)+1){
        for(int i=1;i<=n;i++) scanf("%d",&w[i]);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+w[i];
        int ans=sum[n]*l+(n-1)*ql;
        for(int x=0;x<=n;x++){
            int y=n-x;
            int tmp=sum[x]*l+(sum[n]-sum[x])*r;
            if(x>y) tmp+=max(0,(x-y-1)*ql);
            else    tmp+=max(0,(y-x-1)*qr);
            ans=min(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
