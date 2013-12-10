#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=100000+10;
const int M=100000+10;
int x[N],y[N],pre[N],cnt[N],n;
int u[M],v[M],w[M],type[M],first[N],next[M],e;
int dp[N][2][4];
int ans[N];
void init(){
    memset(first,-1,sizeof(first));

    for(int i=0;i<N;i++)
    dp[i][1][0]=dp[i][0][0]=1;

    e=0;
}
void insert(int f,int t,int val,int kind){
    u[e]=f; v[e]=t; w[e]=val; type[e]=kind;
    next[e]=first[f]; first[f]=e++;
}
int find(int x){
    return pre[x]==x?x:pre[x]=find(pre[x]);
}
void dfs(int x,int fa){
    int flag=0;
    for(int i=first[x];i+1;i=next[i]){
        int y=v[i];
        if(y==fa) continue;
        flag++;

        dfs(y,x);
        if(type[i]==0){
            for(int j=0;j<4;j++) dp[x][0][(j+w[i])%4]+=dp[y][0][j];
            dp[x][0][w[i]%4]+=dp[y][1][0];
        }else if(type[i]==1){
            for(int j=0;j<4;j++) dp[x][1][(j+w[i])%4]+=dp[y][1][j];
            dp[x][1][w[i]%4]+=dp[y][0][0];
        }
    }
    if(flag==0){
       // dp[x][0][0]=dp[x][1][0]=1;
    }
}



void dfs_2(int x,int fa,int g[2][4]){
    int flag=0;
    for(int i=first[x];i+1;i=next[i]){
        int y=v[i];
        if(y==fa) continue;
        flag++;
        if(type[i]==0){
            for(int j=0;j<4;j++) g[0][(j+w[i])%4]-=dp[y][0][j];
            g[0][w[i]%4]-=dp[y][1][0];
        }else if(type[i]==1){
            for(int j=0;j<4;j++) g[1][(j+w[i])%4]-=dp[y][1][j];
            g[1][w[i]%4]-=dp[y][0][0];
        }

        if(type[i]==0){
            for(int j=0;j<4;j++) dp[y][0][(j+w[i])%4]+=g[0][j];
            dp[y][0][w[i]%4]+=g[1][0];
        }else if(type[i]==1){
            for(int j=0;j<4;j++) dp[y][1][(j+w[i])%4]+=g[1][j];
            dp[y][1][w[i]%4]+=g[0][0];
        }

        if(type[i]==0){
            for(int j=0;j<4;j++) g[0][(j+w[i])%4]+=dp[y][0][j];
            g[0][w[i]%4]+=dp[y][1][0];
        }else if(type[i]==1){
            for(int j=0;j<4;j++) g[1][(j+w[i])%4]+=dp[y][1][j];
            g[1][w[i]%4]+=dp[y][0][0];
        }

        int tg[2][4];
        for(int j=0;j<2;j++)
          for(int k=0;k<4;k++)
            tg[j][k]=dp[y][j][k];
        dfs_2(y,x,tg);
    }
        ans[x]+=dp[x][0][0]+dp[x][1][0];
        if(!flag||flag)ans[x]-=2;
}

int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        init();

        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);

        for(int i,j,val,kind,k=1;k<n;k++){
            scanf("%d%d",&i,&j);
            if(x[i]==x[j]) val=abs(y[i]-y[j]),kind=0;
            else val=abs(x[i]-x[j]), kind=1;
            if(val%4==0) pre[find(i)]=find(j);
            insert(i,j,val,kind);
            insert(j,i,val,kind);
        }


        dfs(1,-1);
        int g[2][4];
        for(int i=0;i<2;i++)
         for(int j=0;j<4;j++)
         g[i][j]=dp[1][i][j];
        dfs_2(1,-1,g);


        for(int i=1;i<=n;i++) printf("%d\n",ans[i]>>1);
    }
    return 0;
}
