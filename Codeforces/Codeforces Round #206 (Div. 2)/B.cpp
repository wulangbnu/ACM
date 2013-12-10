#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000+10;
int c[5],n,m,a[N],b[N],cost[N];
int doit(int a[],int n){
    for(int i=1;i<=n;i++)
    cost[i]=min(c[1]*a[i],c[2]);
    int sum=0;
    for(int i=1;i<=n;i++) sum+=cost[i];
    return min(sum,c[3]);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d%d",&c[1],&c[2],&c[3],&c[4])+1){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        int ans=c[4];
        ans=min(ans,doit(a,n)+doit(b,m));
        printf("%d\n",ans);
    }
    return 0;
}
