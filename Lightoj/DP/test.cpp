#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[]={"0123456789ABCDEF"};
int main(){

    freopen("in.cpp","w",stdout);
    printf("%d\n",15*20);
    for(int i=2;i<=16;i++)
    for(int k=1;k<=20;k++){
        printf("%d %d ",i,k);
        for(int j=0;j<i;j++)
        printf("%c",str[j]);
        puts("");
    }
    return 0;
}
