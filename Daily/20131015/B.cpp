#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int N,B;
bool chash[100];
int a[100];
int main(){
    //freopen("in.cpp","r",stdin);
    while(~scanf("%d%d",&N,&B)){
        if(N==0 && B==0) break;
        memset(chash,false,sizeof(chash));
        for(int i=0; i<B; ++i){
            scanf("%d",&a[i]);
        }
        for(int i=0; i<B; ++i)
            for(int j=0; j<B; ++j){
                int ab = abs(a[i]-a[j]);
                chash[ab] = true;
            }
        int flag=true;
        for(int i=0; i<=N; ++i)
            if(chash[i]==false) flag=false;
        if(flag)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
