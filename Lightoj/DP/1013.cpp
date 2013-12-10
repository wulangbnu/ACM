#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=35;
ll dp[N][N];
int f[N][N];
char s[N],t[N];
int n,m;
void doit(){
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    for(int i=0;i<N;i++)
    dp[i][0]=dp[0][i]=1;
    n=strlen(s+1);
    m=strlen(t+1);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    if(s[i]==t[j]){
            f[i][j]=f[i-1][j-1]+1;
            dp[i][j]=dp[i-1][j-1];
            continue;
	    }
	    if(f[i-1][j]>=f[i][j-1]){
            f[i][j]=f[i-1][j];
           dp[i][j]+=dp[i-1][j];
	    }
	    if(f[i][j-1]>=f[i-1][j]){
            f[i][j]=f[i][j-1];
            dp[i][j]+=dp[i][j-1];
	    }
	}
    printf("%d %lld\n",n+m-f[n][m],dp[n][m]);
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s%s",s+1,t+1);
        doit();
    }
    return 0;
}

