#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=20;
ll a[N],b[N][2];
ll dp[N],ten[N];
void init(){
    ten[0]=1;
    for(int i=1;i<=10;i++) ten[i]=ten[i-1]*10;
}
ll doit2(int m,int x){
    int n=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(m){
        a[++n]=m%10;
        b[n][1]=m;
        b[n][0]=b[n-1][0]+a[n]*ten[n-1];
        m/=10;
    }
    for(int i=1;i<n;i++){
        if(x<a[i]) dp[i]=(b[i+1][1])*ten[i-1];
        if(x==a[i]){
            dp[i]=b[i-1][0]+1 + (b[i+1][1]-1)*ten[i-1];
        }
    }


    ll ans=0;
    for(int i=1;i<n;i++){
    //    printf("%d ",dp[i]);
        ans+=dp[i];
    }
  //  puts(" ~~");
//    printf("\n%d\n",ans);
    return ans;
}

ll doit(int m,int x){
    if(x==0) return doit2(m,x);

    int n=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(m){
        a[++n]=m%10;
        b[n][1]=m;
        b[n][0]=b[n-1][0]+a[n]*ten[n-1];
        m/=10;
    }
    for(int i=1;i<=n;i++){
        if(x<a[i]) dp[i]=(b[i+1][1]+1)*ten[i-1];
        if(x==a[i]){
            dp[i]=b[i+1][1]*ten[i-1]+(b[i-1][0]+1);
        }
        if(x>a[i]){
            dp[i]=b[i+1][1]*ten[i-1];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
  //      printf("%d ",dp[i]);
        ans+=dp[i];
    }
//    printf("\n%d\n",ans);
    return ans;
}

void test(){
    doit(321,3);
}
int main(){
    //freopen("Din.cpp","r",stdin);
    init();
    //test();
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n+m)){
        for(int i=0;i<10;i++)
        printf("%lld%c",doit(m,i)-doit(n-1,i),i==9?'\n':' ');
    }
    return 0;
}
