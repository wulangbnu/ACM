#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
int a[N],n,k;
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    while(scanf("%d%d",&n,&k)==2){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int tmp=1000000000,x;
        for(int i=1;i<=k;i++){
            int tot=0;
            for(int j=i;j<=n;j+=k) tot+=a[j];
            if(tot<tmp) {
                tmp=tot;
                x=i;
            }
            //printf("%d %d\n",i,tot);
        }
        printf("%d\n",x);
    }
    return 0;
}
