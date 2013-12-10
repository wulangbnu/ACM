#include<cstdio>
#include<cstring>
typedef long long ll;
const int N=60+10;
ll dp[N][N];
char str[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k,r;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        n=strlen(str);
        for(i=0;i<n;i++){
            dp[i][i]=1;
            dp[i][i+1]=2+(str[i]==str[i+1]);
        }
        for(k=2;k<n;k++)
        for(i=0;i+k<n;i++){
            if(str[i]!=str[i+k]) dp[i][i+k]=dp[i][i+k-1]+dp[i+1][i+k]-dp[i+1][i+k-1];
            else dp[i][i+k]=dp[i][i+k-1]+dp[i+1][i+k]+1;
        }
        printf("Case %d: %lld\n",cas++,dp[0][n-1]);
    }
    return 0;
}
