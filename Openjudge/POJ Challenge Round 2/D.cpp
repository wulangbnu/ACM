#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=5000000;
long double dp[N];
void init(){
    dp[1]=1.0;
    for(int i=2;i<N;i++) dp[i]=dp[i-1]+1.0/i;
}
int main(){
    //freopen("in.cpp","r",stdin);
    init();
    ll n;
    while(cin>>n){
        //cout<<dp[2]<<endl;
        double ans;
        if(n<N) ans=dp[n]-1+dp[n]/n;
        else{
            double tmp=log(n+1)+0.57721566490153286060651209;
            ans=tmp-1+tmp/n;
        }
//        long double ans=log((long double)n)+(long double)0.57721566490153286060651209;
//        printf("%.9f\n",(double)ans);
//
//        n=min(n,N-1);
        printf("%.9f\n",(double)ans);
    }
    return 0;
}
