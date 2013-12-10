#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1005;
const int M=3;

int ans[N][N];
void init() {
    ans[0][0]=-1;
    ans[0][1]=1;
    ans[1][0]=0;
    ans[1][1]=1;
    for(int t=2; t<=8; t++) {
        for(int i=0; i<(1<<(t-1)); i++)
            for(int j=0; j<(1<<(t-1)); j++)
                ans[i+(1<<(t-1))][j+(1<<(t-1))]=ans[i][j];
        for(int i=0; i<(1<<(t-1)); i++)
            for(int j=0; j<(1<<(t-1)); j++) {
                ans[i][j+(1<<(t-1))]=-1;
                ans[i+(1<<(t-1))][j]=1;
            }
    }
}
void output(int x) {
    for(int i=0; i< x; i++) {
        bool sign=0;
        for(int j=0; j< x; j++) {
            if(sign)printf(" ");
            else sign=1;
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
}

int b[3][3]={
    0,1,0,
    1,1,0,
    1,1,1
};
int MOD;
struct Mat{
    int a[M][M];
    Mat operator *(Mat tt){
        Mat tmp;
        for(int i=0;i<M;i++)
        for(int j=0;j<M;j++){
            tmp.a[i][j]=0;
            for(int k=0;k<M;k++)
            tmp.a[i][j]+=a[i][k]*tt.a[k][j];
            tmp.a[i][j]%=MOD;
        }
        return tmp;
    }
}M1,M2;
int doit(int n){
    for(int i=0;i<M;i++)
    for(int j=0;j<M;j++)
    M1.a[i][j]=b[i][j];

    for(int i=0;i<M;i++)
    for(int j=0;j<M;j++)
    M2.a[i][j]=(i==j);
    while(n>0){
        if(n&1) M2=M2*M1;
        M1=M1*M1;
        n>>=1;
    }
    return (M2.a[2][0]*1+M2.a[2][1]*1+M2.a[2][2]*2)%MOD;
}
int main() {
    //freopen("in.cpp","r",stdin);
    init();
    int T,n,m,cas=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        MOD=m;
        int sn=doit(n-2);

        printf("Case %d: ",cas++);
        if( !(sn>=2&&sn%2==0) ) puts("No");
        else {
            puts("Yes");
            output(sn);
        }
    }
    return 0;
}
