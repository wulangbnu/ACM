#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=200000+10;
int n;
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        int Max=-1,ans=-1,a,b;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(a<=Max) continue;
            Max=a;
            ans=max(ans,b);
        }
        printf("%d\n",ans);
    }
    return 0;
}
