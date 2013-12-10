#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
int x[100];
int main(){
    freopen("in.cpp","w",stdout);
    srand(time(0));
    int n = rand()%100+1;
    if(n&1) n++;
    printf("%d\n",n/2);
    int a = 23;
    int b = 10;
    x[0] = rand()%1000;
    for(int i=1;i<=n;i++){
        x[i]=(x[i-1]*a+b)%10001;
    }
    for(int i=1;i<=n;i+=2){
        printf("%d\n",x[i]);
    }
    return 0;
}
