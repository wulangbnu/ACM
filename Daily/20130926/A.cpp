#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    //freopen("in.cpp","r",stdin);
    int n;
    while(scanf("%d",&n)+1){
        int ans=0;
        for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        if(i+j==n) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
