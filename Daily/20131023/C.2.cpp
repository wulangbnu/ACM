#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int M=20000000+10;
bool f[M];
ll fi[100];
int a[2000000+10];
void init(){
//    fi[0]=1;
//    fi[1]=2;
//    for(int i=2;i<100;i++) fi[i]=fi[i-1]+fi[i-2];

    f[0]=true;
    f[1]=false;
    f[2]=false;
    for(int i=2;i<M;i++){
        if(f[i]) continue;
        for(int j=i+i;j<M;j+=i)
        f[j]=true;
    }
    int tot=0;
    for(int i=0;i<M;i++){
        if(f[i]) continue;
        //if(i<100) cout<<i<<" "<<fi[i]<<endl;
        a[tot++]=i;
    }
    //cout<<tot<<endl;
    //cout<<a[1]<<endl;
}
#define N 2
ll MOD;
struct Matrix{
    ll a[N][N];
    Matrix operator *(Matrix tt){
        Matrix tmp;
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            tmp.a[i][j]=0;
            for(int k=0;k<N;k++)
            tmp.a[i][j]+=a[i][k]*tt.a[k][j];
            tmp.a[i][j]%=MOD;
        }
        return tmp;
    }
}M1,M2;
void doit(int n,ll &y,ll &z){
    if(n==1){
        y=2%MOD;
        z=1;
        return;
    }
    if(n==2){
        y=3%MOD;
        z=2%MOD;
        return;
    }

    n-=2;
    M1.a[0][0]=0;
    M1.a[0][1]=M1.a[1][0]=M1.a[1][1]=1;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    M2.a[i][j]=(i==j?1:0);
    while(n>0){
        if(n&1) M2=M2*M1;
        M1=M1*M1;
        n>>=1;
    }
    y=(2*M2.a[0][1]+3*M2.a[1][1])%MOD;
    z=3*(M2.a[1][0])%MOD;
}
int main(){
    freopen("in.cpp","r",stdin);
    init();
    ll T,k,x,y,z,m;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&k,&x,&m);
        MOD=x*m;
        cout<<a[k-1]<<endl;
        doit(a[k],y,z);
        cout<<y<<" "<<z<<endl;
        while(y%x){
            swap(z,y);
            y=(z+y)%MOD;
            //cout<<y<<endl;
        }
        printf("%lld\n",y/x);
    }
    return 0;
}
