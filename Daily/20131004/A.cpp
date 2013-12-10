#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int sh,sm,dh,dm;
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&sh,&sm,&dh,&dm);
        dh=(sh+dh)+(sm+dm)/60;
        dm=(sm+dm)%60;
        puts("------+---------");
        puts(" time | elapsed");
        puts("------+---------");
        int t=sm;
        if(t) printf("%2d:XX | XX - %d\n",sh,t);
        else  printf("%2d:XX | XX\n",sh,t);
        for(int j=60,i=sh+1;i<=dh;i++,j+=60){
            int x=i;
            if(x>12) x-=12;
            int y=j-t;
            printf("%2d:XX | XX + %d\n",x,y);
        }
    }
    return 0;
}
