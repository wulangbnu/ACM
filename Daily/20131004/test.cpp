#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    freopen("in.cpp","w",stdout);
    for(int i=1;i<100;i++)
    for(int j=i+1;j<100;j++){
        if(__gcd(i,j)!=1) continue;
        printf("%d %d\n",i,j);
    }
    puts("0 0");
    return 0;
}
