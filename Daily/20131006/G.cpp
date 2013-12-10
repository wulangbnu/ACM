#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int a[21] = {0,0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
void doit_min(int n){
    string ss="";
    while(n>20){
        ss+="8";
        n-=7;
    }
    printf("%d",a[n]);
    cout<<ss;
}
void doit_max(int n){
    int x=n/2-1;
    if(n&1) printf("7");
    else printf("1");
    for(int i=0;i<x;i++) printf("1");
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        doit_min(n); printf(" "); doit_max(n); puts("");
    }
    return 0;
}
