#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    int n,a,b,c,d;
    scanf("%d",&n);
    int x=-1,ans=-1;
    for(int i=1;i<=4;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a=min(a,b), c=min(c,d);
        if(a+c<=n){
            ans=a;
            x=i;
        }
    }
    if(ans==-1) puts("-1");
    else printf("%d %d %d\n",x,ans,n-ans);
    return 0;
}
