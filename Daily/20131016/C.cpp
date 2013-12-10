#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100+10;
char str[N][N];
int n,m;
int pre[N][N],to[N][N],dp[N][N][N];
void doit(int dp[][N],int k,char str[],int pre[],int to[]){

    for(int i=1;i<=m;i++){
        if(str[i]=='0') continue;
        int j=i+(str[i]-'0')-1;
        pre[j]=i;
        for(int k=i;k<=j;k++) to[k]=i;
        i=j;
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            dp[i][j]=dp[i][j-1]+(j-pre[j]+1)*(pre[j]>=i);
            //printf("%d %d %d\n",i,j,dp[i][j]);
        }
    }
}
void solve(){

    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));

    for(int i=1;i<=n;i++)
    doit(dp[i],i,str[i],pre[i],to[i]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        for(int k=j;k<=m;k++){
            int x=j, y=k;

            //if(i==3&&j==1&&k==3) printf("~~%d %d %d %d\n",x,y,to[i-1][x],to[i-1][y]);
            while(x<=m&&str[i-1][x]!='0'&& to[i-1][x]<j) x++;
            while(y>=1&&str[i-1][y]!='0'&& to[i-1][y]+str[i-1][to[i-1][y]]-'0'-1>k) y--;

           // if(i==3&&j==1&&k==3) printf("~~%d %d\n",x,y);
            while(str[i-1][x-1]=='0') x--;
            while(str[i-1][y+1]=='0') y++;
            dp[i][j][k]+=dp[i-1][x][y];

           // printf("!!! %d %d %d %d \n",i,j,k,dp[i][j][k]);
        }
    }
    //printf("!! %d \n",dp[2][1][3]);

    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(pre[i][j]==-1) continue;
        int x=pre[i][j], y=j;
        while(str[i][x-1]=='0') x--;
        while(str[i][y+1]=='0') y++;
        //printf("%d %d %d %d\n",i,x,y,dp[i][x][y]);
        ans=max(ans,dp[i][x][y]);
    }
    printf("%d\n",ans);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)&&n+m){
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        solve();
    }
    return 0;
}
