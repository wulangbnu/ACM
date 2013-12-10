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
void solve(int x,int &y,ll &xx,ll &yy){
    if(x<y){
        y=x;
        yy=xx;
    }
    else if(x==y){
        yy+=xx;
    }
}
void doit(){
    n=strlen(s+1);
    m=strlen(t+1);
    memset(f,0x3f,sizeof(f));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++){
        f[i][0]=f[0][i]=i;
        dp[i][0]=dp[0][i]=1;
    }
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    //枚举放在最后的元素
	    if(s[i]==t[j]){
            solve(f[i-1][j-1]+1,f[i][j],dp[i-1][j-1],dp[i][j]);
	    }
	    else{
            solve(f[i-1][j]+1,f[i][j],dp[i-1][j],dp[i][j]);
            solve(f[i][j-1]+1,f[i][j],dp[i][j-1],dp[i][j]);
	    }
	}
	printf("%d %lld\n",f[n][m],dp[n][m]);
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

