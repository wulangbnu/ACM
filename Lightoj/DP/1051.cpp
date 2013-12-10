#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=55;
const int INF=100;
char str[N];
int f[N],g[N];
int dp[N][2],ds[N][2];
int n;
bool checkbad(){
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++){
        if(str[i]==0||str[i]=='?') f[i]=f[i-1]+1;
        if(str[i]==1||str[i]=='?') g[i]=g[i-1]+1;
        if(f[i]>=5||g[i]>=3) return true;
    }
    return false;
}
bool checkgood(){
    for(int i=1;i<=n;i++){
        if(str[i]==1){
            dp[i][0]=ds[i][0]=INF;
            if(ds[i][1]<5) dp[i][1]=dp[i-1][1]+1;
            ds[i][1]=0;
        }
        else if(str[i]==0){
            dp[i][1]=ds[i][1]=INF;
            dp[i][0]=0;
            ds[i][0]=ds[i-1][0]+1;
        }
        else{
            dp[i][1]=min()
        }
    }
    return true;
}
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=1,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",str+1);
        n=strlen(str+1);
        for(i=1;i<=n;i++){
            if(str[i]=='?') continue;
            if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U') str[i]=1;
            else str[i]=0;
        }
        bool x=checkbad(), y=checkgood();
        if(x&&y) puts("MIXED");
        else if(x) puts("BAD");
        else puts("GOOD");
    }
    return 0;
}
