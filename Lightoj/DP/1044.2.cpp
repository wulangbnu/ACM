#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1000+10;
char str[N];
int dp[N];
vector<int> adj[N];
bool f[N][N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",str+1);
        n=strlen(str+1);
        for(i=1;i<=n;i++){
            f[i][i]=true; adj[i].push_back(i);
            if(str[i]==str[i+1]){
                f[i][i+1]=true; adj[i+1].push_back(i);
            }
            else f[i][i+1]=false;
        }
        for(k=2;k<n;k++)
        for(i=1;i+k<=n;i++){
            f[i][i+k]=(str[i]==str[i+k])&&f[i+1][i+k-1];
            if(f[i][i+k]) adj[i+k].push_back(i);
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(i=1;i<=n;i++)
        for(j=0;j<adj[i].size();j++){
            dp[i]=min(dp[i],dp[adj[i][j]-1]+1);
        }
        printf("%d\n",dp[n]);
        for(i=1;i<=n;i++) adj[i].clear();
    }
    return 0;
}
