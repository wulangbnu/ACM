#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int a[4];

int main() {
    //freopen("in.cpp","r",stdin);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--) {
        int sum=0;
        for(int i=0; i<4; i++)scanf("%d",&a[i]),sum+=a[i];
        bool sign=0;
        for(int i=1; i<4; i++)if((a[0]+a[i])*2==sum) {
                sign=1;
                printf("Case %d: Yes\n",++ncase);
                break;
            }
        if(!sign)printf("Case %d: No\n",++ncase);
    }
    return 0;
}
