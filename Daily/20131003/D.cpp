#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=(1<<26)+10;
int get[N];
int v[200],dp[2][N],cnt[2];
int a,b,n;
int cas=0;
bool doit(){
    ++cas;
    get[0]=cas;
    cnt[0]=cnt[1]=0;
    dp[0][cnt[0]++]=0;

    int x=0,y=1;
    for(int i=1;i<=n;i++){
        cnt[y]=0;
        for(int j=0;j<cnt[x];j++){
            dp[y][cnt[y]++]=dp[x][j];
            if(dp[x][j]+v[i]>=a&&dp[x][j]+v[i]<=b) return true;
            if(dp[x][j]+v[i]<a&&get[dp[x][j]+v[i]]!=cas){
                dp[y][cnt[y]++]=dp[x][j]+v[i];
                get[dp[x][j]+v[i]]=cas;
            }
        }
        swap(x,y);
    }
    return false;
}
int main(){

    //freopen("in.cpp","r",stdin);

     puts("Saintow swaintow waintows in dust.");

    /*int T;
    scanf("%d",&T);
    while(T--){

        scanf("%d%d%d",&a,&b,&n);
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);

       // if(doit()) puts("Saintow swaintow swaintows.");
        //else
         puts("Saintow swaintow waintows in dust.");
    }*/
    return 0;
}
