#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;
const int N=1000000+10;
int a[N];
int main(){
    freopen("in.cpp","w",stdout);
    srand(time(0));

    int n=rand()%1000000;
    for(int i=1;i<=n;i++) a[i]=i;

    int T=10;
    while(T--){
        random_shuffle(a+1,a+n+1);
         printf("%d\n",n);
         for(int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
    }

    return 0;

}
