#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=60+10;
ll dp[N][N];
char str[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k,r;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",str);
        n=strlen(str);
        memset(dp,0,sizeof(dp));
        ll ans=0;
        for(k=0;k<n;k++)
        for(i=0;i+k<n;i++){
            if(str[i]!=str[i+k]) continue;
            dp[i][i+k]++;
            for(j=i+1;j<i+k;j++)
            for(r=j;r<i+k;r++)
            dp[i][i+k]+=dp[j][r];
            ans+=dp[i][i+k];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
