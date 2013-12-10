#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=987654321;
int main(){
    //freopen("in.cpp","r",stdin);

    ll k=sqrt(N+0.5);
    cout<<k<<endl;
    for(ll i=k;i<1000000000;i++)
    if(i*i%1000000000==987654321) cout<<i<<endl;

    return 0;
}
