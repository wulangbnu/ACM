#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=10+10;
char str[N][200];
int v[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<10;i++) scanf("%s %d",str[i],&v[i]);
        int tmp=v[0];
        for(int i=0;i<10;i++) tmp=max(tmp,v[i]);
        printf("Case #%d:\n",++cas);
        for(int i=0;i<10;i++)
        if(v[i]==tmp) printf("%s\n",str[i]);
    }
    return 0;
}
