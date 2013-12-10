#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void doit(int x){
    if(x==0){
        puts("0");
        return;
    }
    string ss="";
    while(x){
        ss+=x%6+'0';
        x/=6;
    }
    for(int i=ss.size()-1;i>=0;i--) printf("%c",ss[i]);
    puts("");
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        doit(n);
    }
    return 0;
}
