#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000+10;
int dp[N][N],next[N],pre[N];
char str[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",str);
        n=strlen(str);
        for(i=0;i<n;i++){
            next[i]=i; pre[i]=i;
            dp[i][i]=1;
            if(str[i]==str[i+1]){
                dp[i][i+1]=1;
                next[i]=i+1; pre[i+1]=i;
            }
            else  dp[i][i+1]=2;
        }
        for(k=2;k<n;k++)
        for(i=0;i+k<n;i++){
            if(str[i]==str[i+k]&&dp[i+1][i+k-1]==1){
                 dp[i][i+k]=1;
                 next[i]=i+k; pre[i+k]=i;
            }
            else dp[i][i+k]=min(dp[next[i]+1][i+k],dp[i][pre[i+k]-1])+1;
         }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
