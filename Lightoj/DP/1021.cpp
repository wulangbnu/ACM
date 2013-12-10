#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=16;
typedef long long ll;
ll dp[20][1<<N],a[N+1][N];
char str[20];
int b[1<<N];
void init(){
    for(int i=2;i<=16;i++){
        a[i][0]=1;
        for(int j=1;j<i;j++)
        a[i][j]=a[i][j-1]*i;
    }
    for(int i=1;i<(1<<N);i++)
    for(int j=0;j<N;j++)
    if(i&(1<<j)) b[i]++;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,base,i,j,k,r,m;
    init();
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&base,&m);
        scanf("%s",str);
        n=strlen(str);
        for(i=0;i<n;i++){
            if(str[i]<'A') str[i]-='0';
            else str[i]=str[i]-'A'+10;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0;i<(1<<n);i++){
            for(j=0;j<n;j++){
                if(i&(1<<j)) continue;
                r=(a[base][b[i]]%m)*str[j]%m;
                for(k=0;k<m;k++){
                    dp[(k+r)%m][i|(1<<j)]+=dp[k][i];
                }
            }
        }
        printf("%lld\n",dp[0][(1<<n)-1]);
    }
    return 0;
}
