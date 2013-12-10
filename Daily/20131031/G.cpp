#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int bs(int H,int h) {
    return (H/h+1)/2;
}
int W,w,H,h;
int main() {
    //freopen("garage.in","r",stdin);
    //freopen("garage.out","w",stdout);
    scanf("%d%d%d%d",&W,&H,&w,&h);
    printf("%d\n",bs(W,w)*bs(H,h));
    return 0;
}
