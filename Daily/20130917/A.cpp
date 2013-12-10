#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        int x;
        scanf("%d",&x);
        x/=10;
        printf("Case #%d:\n",cas++);
        puts("*------------*");
        for(int i=0;i<10-x;i++)
        puts("|............|");
        for(int i=0;i<x;i++)
        puts("|------------|");
        puts("*------------*");
    }
    return 0;
}
