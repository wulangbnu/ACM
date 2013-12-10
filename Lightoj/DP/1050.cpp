#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=500+10;
double dp[N][N];
void init(){
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    dp[i][j]=-10.0;
}
double dfs(int x,int y){
    if(x<0||y<0) return 0;
    if(dp[x][y]>-1.0) return dp[x][y];
    if(x+y==1){
        if(x==1) dp[x][y]=0.0;
        else dp[x][y]=1.0;
    }
    else if((x+y)&1){
        double p=x*1.0/(x+y);
        dp[x][y]=p*dfs(x-1,y)+(1.0-p)*dfs(x,y-1);
    }
    else{
        if(y==0) dp[x][y]=0.0;
        else dp[x][y]=dfs(x,y-1);
    }
    return dp[x][y];
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,n,i,j,k,cas=1;
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%d%d",&i,&j);
        printf("Case %d: %.9f\n",cas++,dfs(i,j));
    }
    return 0;
}
