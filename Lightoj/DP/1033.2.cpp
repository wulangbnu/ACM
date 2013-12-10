#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;
char str[N];
int dp[N][N];
int main(){
   // freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        n=strlen(str);
        for(i=0;i<n;i++){
            dp[i][i]=0;
            dp[i][i+1]=(str[i]!=str[i+1]);
        }
        for(k=2;k<n;k++)
        for(i=0;i+k<n;i++){
            if(str[i]==str[i+k]) dp[i][i+k]=dp[i+1][i+k-1];
            else dp[i][i+k]=min(dp[i+1][i+k],dp[i][i+k-1])+1;
        }
        printf("Case %d: %d\n",cas++,dp[0][n-1]);
    }
    return 0;
}
