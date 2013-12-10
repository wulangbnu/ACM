#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
bool check(ll x){
    ll y=sqrt(x)+0.5;
    return y*y==x;
}
ll doit(int d){
    for(ll i=1;;i++){
       // if(i%1000==0) cout<<i<<endl;
        if(check(d*i*i+1))return i;
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    //cout<<doit(157)<<endl;
    //157 4182813984
    ll ans=4182813984ll;
    for(int i=158;i<=1000;i++){
        if(check(i)) continue;
        //printf("%d %lld\n",i,doit(i));
        ll now=doit(i);
        printf("%d \n",i);
        if(now>ans){
            printf("~~~ %d\n",i);
            ans=now;
        }
    }
    cout<<ans<<endl;
    return 0;
}
