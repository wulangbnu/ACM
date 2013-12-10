#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    //freopen("in.cpp","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)+1){
        if(m==0){
            if(n==1)puts("0");
            else puts("No solution");
            continue;
        }
//        for(int i=1;i<=n-1;i++) printf("1");
//        for(int j=1;j<10;j++){
//            if((n-1+j+8)%9+1==m){
//                printf("%d\n",j);
//                break;
//            }
//        }
        printf("%d",m);
        for(int i=1;i<=n-1;i++) printf("0");
        puts("");

    }
    return 0;
}
