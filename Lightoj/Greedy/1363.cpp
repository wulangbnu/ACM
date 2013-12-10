#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000+10;
char str[N][N];
int ro[N],co[N],tmp[N];
int doit(int a[],int n,int val){

    int i,j;
    int ret1=0,ret2=0;
    memcpy(tmp,a,sizeof(co));
    for(j=1,i=0;i<n;i++){
        if(tmp[i]==val) continue;
        int k=tmp[i]-val;
        for(;j<n&&k!=0;j++)
        if(val-tmp[j]<=k){
            tmp[i]-=val-tmp[j];
            tmp[j]=val;
            k-=val-tmp[j];
            ret1+=(val-tmp[j])*(j-i);
        }
    }

    memcpy(tmp,a,sizeof(co));
    for(j=n-2,i=n-1;i>=0;i--){
        if(tmp[i]==val) continue;
        int k=tmp[i]-val;
        for(;j>=0&&k!=0;j--)
        if(val-tmp[j]<=k){
            tmp[i]-=val-tmp[j];
            tmp[j]=val;
            k-=val-tmp[j];
            ret2+=(val-tmp[j])*(i-j);
        }
    }
    return min(ret1,ret2);
}
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int sum=0;
        memset(ro,0,sizeof(ro));
        memset(co,0,sizeof(co));
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
            for(j=0;j<m;j++){
                k=str[i][j]=='1';
                sum+=k;
                ro[i]+=k;
                co[j]+=k;
            }
        }
        printf("Case %d: ",cas++);
        if(sum%n==0&&sum%m==0) printf("both %d\n",doit(ro,n,sum/n)+doit(co,m,sum/m));
        else if(sum%n==0)      printf("row %d\n",doit(ro,n,sum/n));
        else if(sum%m==0)      printf("column %d\n",doit(co,m,sum/m));
        else puts("impossible");
    }
    return 0;
}
