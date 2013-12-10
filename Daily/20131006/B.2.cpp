#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=20000+10;
int n,m,in[N],out[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        while(m--){
            int i,j;
            scanf("%d%d",&i,&j);
            in[j]++;
            out[i]++;
        }
        int ans[2]={0,0};
        for(int i=1;i<=n;i++){
            if(in[i]==0) ans[0]++;
            if(out[i]==0) ans[1]++;
        }
        if(n==1) printf("0\n");
        else{
            printf("%d\n",max(ans[0],ans[1]));
        }
    }
    return 0;
}
