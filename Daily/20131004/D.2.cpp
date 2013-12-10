#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=30000*250+10;
const int M=30000;
int x[N],y[N],cnt,n;
ll ans;
int p[M*2+10];
void doit(int a[]){
    memset(p,0,sizeof(p));
    for(int i=0;i<cnt;i++) p[a[i]]++;
    for(int i=0;i<=n;i++)
    if(p[i]-1>0) ans+=p[i]-1;
}
void work(int a[],int b[]){
    memset(p,0,sizeof(p));
    for(int i=0;i<cnt;i++) p[a[i]+b[i]]++;
    for(int i=0;i<=n+n;i++)
    if(p[i]-1>0) ans+=p[i]-1;
}
void work2(int a[],int b[]){
    memset(p,0,sizeof(p));
    for(int i=0;i<cnt;i++) p[a[i]-b[i]+30000]++;
    for(int i=0;i<M*2+10;i++)
    if(p[i]-1>0) ans+=p[i]-1;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)&&n){
        int t;
        cnt=0;
        scanf("%d",&t);
        while(t--){
            int k,xx,yy,s,t;
            scanf("%d%d%d%d%d",&k,&xx,&yy,&s,&t);
            for(int i=0;i<k;i++){
                x[cnt]=xx+i*s;
                y[cnt++]=yy+i*t;
            }
        }
        ans=0;
        doit(x);
        doit(y);
        work(x,y);
        work2(x,y);
        printf("%lld\n",ans);
    }
    return 0;
}
