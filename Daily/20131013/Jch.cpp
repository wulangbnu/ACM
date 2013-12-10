#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000+10;
struct Point{
    int x,y;
    bool operator < (const Point &tt) const{
        return x<tt.x;
    }
}p[N];
int n,dp[N];
int main(){

    freopen("in.cpp","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        sort(p+1,p+1+n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int num = 1;
            dp[i] = dp[i-1];
            for(int j=i-1;j>=0;j--){
                if(p[j].y>p[i].x)
                    num++;
                if(num>=2)
                    dp[i]=max(dp[i],dp[j]+num);
            }
            //printf("~~ %d %d\n",i,dp[i]);
        }
        printf("Case #%d: %d\n",++cas,dp[n]);
    }
    return 0;
}
