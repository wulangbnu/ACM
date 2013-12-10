#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
int a[N],n;
int dp[N];
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            if(a[i]==a[i-1]+a[i-2]) dp[i]=dp[i-1]+1;
            else dp[i]=2;
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
