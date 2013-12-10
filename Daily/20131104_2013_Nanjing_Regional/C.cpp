#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD=1000000000+7;
const int N=100+10;
const int M=10+1;
char str[N][M];
int n,m,c,d;
ll dp[2][1<<M][25];
void solve(){
    memset(dp,0,sizeof(dp));
    dp[0][(1<<m)-1][0]=1;
    int x=0,y=1;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        memset(dp[y],0,sizeof(dp[y]));
        for(int k=0;k<(1<<m);k++)
        for(int r=0;r<=d;r++){
            if(dp[x][k][r]==0) continue;
            int now=(k<<1)&((1<<m)-1);

            if(str[i][j]=='1'){
                //不放
                if(k&(1<<(m-1))) dp[y][now][r]=(dp[y][now][r]+dp[x][k][r])%MOD;
                //放1*1
                if((k&(1<<(m-1)))&&r+1<=d) dp[y][now^1][r+1]=(dp[y][now^1][r+1]+dp[x][k][r])%MOD;
                //竖放1*2
                if(!(k&(1<<(m-1)))&&i>0) dp[y][now^1][r]=(dp[y][now^1][r]+dp[x][k][r])%MOD;
                //横放1*2
                if(!(k&1)&&j>0&&(k&(1<<(m-1)))) dp[y][now^3][r]=(dp[y][now^3][r]+dp[x][k][r])%MOD;
            }else{
                if(k&(1<<(m-1))) dp[y][now^1][r]=(dp[y][now^1][r]+dp[x][k][r])%MOD;
            }
        }
        swap(x,y);
    }
    ll ans=0;
    for(int i=c;i<=d;i++)
    ans=(ans+dp[x][(1<<m)-1][i])%MOD;
    cout<<ans<<endl;
}
int main(){
    //freopen("C.in.cpp","r",stdin);
    while(scanf("%d%d%d%d",&n,&m,&c,&d)+1){
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        solve();
    }
    return 0;
}
