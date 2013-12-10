/**
 **用log解决幂次的精度问题
**/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N=400000+10;
double lg[N];
void init(){
    lg[0]=lg[1]=0.0;
    for(int i=2;i<N;i++) lg[i]=lg[i-1]+log(i*1.0);
}
double solve(int n,double p){
    double lp=log(p),lq=log(1-p),ans=0;
    for(int m=0;m<=n;m++){
        ans+=exp(lg[n+m]-lg[n]-lg[m]+n*lp+m*lq+log(n-m*1.0));
    }
    return p*ans;
}
int main(){
    freopen("in.cpp","r",stdin);
    int n,cas=0;
    double p;
    init();
    while(scanf("%d%lf",&n,&p)+1){
        printf("Case %d: %.6f\n",++cas,solve(n,p)+solve(n,1-p));
    }
    return 0;
}
