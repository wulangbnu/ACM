#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace  std;
const int N=100000+10;
double dp[N];
int a[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    dp[1]=-1.0;
    a[1]=1;
    for(i=1;i<N;i++){
        dp[i]=(dp[i]+1.0)/a[i];
        for(j=i+i;j<N;j+=i){
            dp[j]+=dp[i]+1;
            a[j]++;
        }
    }
    while(T--){
        scanf("%d",&n);
        printf("Case %d: %.9f\n",cas++,dp[n]);
    }
    return 0;
}
