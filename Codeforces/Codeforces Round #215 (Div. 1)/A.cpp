#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
char str[N];
int a[3][N];
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    while(scanf("%s",str+1)+1){
        memset(a,0,sizeof(a));
        int n=strlen(str+1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++) a[j][i]=a[j][i-1];
            if(str[i]=='x') a[0][i]++;
            else if(str[i]=='y') a[1][i]++;
            else if(str[i]=='z') a[2][i]++;
        }
        int m;
        scanf("%d",&m);
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            if(r-l+1<3) puts("YES");
            else {
                int x[3];
                for(int i=0;i<3;i++)
                x[i]=a[i][r]-a[i][l-1];
                sort(x,x+3);
                if(x[2]-x[0]<=1) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}
