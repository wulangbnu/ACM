#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dp[35];
void init(){
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<35;i++){
        dp[i]=(1<<i)/2+1;
        for(int j=1;j<i;j++)
        dp[i]=min(dp[i],dp[j]*dp[i-j]);
    }
}
void doit(int n){

    if(n==1){
        puts("1");
        return;
    }

    int x=0,ans=1;
    while(!(n&1)){
        n>>=1;
        x++;
    }
    if(x) ans*=dp[x];

    //cout<<"!!"<<n<<" "<<ans<<endl;
    for(int i=3;i*i<=n;i++){
        while(n&&n%i==0){
            ans*=i/2+1;
            n/=i;
        }
    }

    if(n>1) ans*=n/2+1;
    printf("%d\n",ans);
}
int main(){
    //freopen("in.cpp","r",stdin);
    //freopen("out.cpp","w",stdout);
    init();
    int n;
    while(scanf("%d",&n)+1)
    //for(int n=1;n<110;n++)
    doit(n);

    return 0;
}
