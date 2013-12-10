#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=90;
ll f[N];
void init(){
    f[0]=1;
    f[1]=2;
    for(int i=2;i<N;i++){
        f[i]=f[i-1]+f[i-2];
        //printf("%d %lld ",i,f[i]);
        int j,flag=1;
        for(j=1;j<i&&flag;j++) if(__gcd(f[i],f[j])>1) flag=0;
        if(flag) printf("!!! %d \n",i);
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    init();
    return 0;
}
