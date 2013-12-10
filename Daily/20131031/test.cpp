#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=10;
int main(){
    //freopen("in.cpp","r",stdin);
    freopen("in.cpp","w",stdout);
    for(int a=1;a<=N;a++)
    for(int b=1;b<=N;b++)
    for(int c=1;c<=N;c++)
    for(int d=1;d<=N;d++){
        printf("%d %d %d %d\n",a,b,c,d);
    }

    return 0;
}
