#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int a[5000+10];
int main(){
    freopen("in.cpp","w",stdout);
    int n=1000;
    for(int i=0;i<5*n;i++) a[i]=i+1;
    int T=1000;
    while(T--){
        printf("%d\n",n);
        random_shuffle(a,a+n*5);
        for(int i=0;i<5*n;i++)
        printf("%d ",a[i]);
        puts("");
    }
    printf("0");
    return 0;
}
