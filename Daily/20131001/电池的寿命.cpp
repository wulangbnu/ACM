#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000+10;
int n,a[N];
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int sum=0;
        for(int i=1;i<n;i++) sum+=a[i];
        if(sum<a[n]) printf("%d.0\n",sum);
        else printf("%.1f\n",(sum+a[n])/2.0);
    }
    return 0;
}
