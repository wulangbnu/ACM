#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=16;
const int INF=0x3f3f3f3f;
int dp[1<<N],f[N][N],a[1<<N],n;
void init(){
    for(int i=0;i<N;i++) a[1<<i]=i;
}
struct Point{
    int x,y;
    bool input(){
        scanf("%d%d",&x,&y);
    }
}p[N];
bool check(Point p1,Point p2,Point p3){
    p2.x-=p1.x; p2.y-=p1.y;
    p3.x-=p1.x; p3.y-=p1.y;
    return (p2.x*p3.y==p2.y*p3.x);
}
int dfs(int x){
    if(dp[x]!=INF) return dp[x];
    int i=a[x&-x];
    for(int k=x-(x&-x);k;k-=k&-k){
        int j=a[k&(-k)];
        dp[x]=min(dp[x],dfs(x^(f[i][j]&x))+1);
    }
    return dp[x];
}
int main(){

    //freopen("in.cpp","r",stdin);
    int T,cas=1,i,j,k;
    init();
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=0;i<n;i++) p[i].input();
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++){
            for(k=0;k<n;k++)
            if(check(p[i],p[j],p[k])) f[i][j]|=1<<k;
            f[j][i]=f[i][j];
         }
         memset(dp,0x3f,sizeof(dp));
         dp[0]=0;
         for(i=0;i<n;i++) dp[1<<i]=1;
         printf("%d\n",dfs((1<<n)-1));
    }
    return 0;
}
