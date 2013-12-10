#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN = 1000010;
int odd[MAXN],even[MAXN];
int a[MAXN];
int N,K;

void init(){
    for(int i=0; i<N; ++i)
        scanf("%d",&a[i]);

    for(int i=0; i<K; ++i){
        int sum = 0;
        int ji=0,ou=0;
        for(int j=i; j<N; j+=K){
            sum++;
            if( (a[j]&1) ){
                ji++;
            }
            else{
                ou++;
            }
        }
        odd[i+1] = ji;
        even[i+1] = ou;
    }
}

int f[MAXN][2];

void pd(int &ret,int val)
{
    if(ret==-1)ret=val;
    else ret=min(ret,val);
}

void dp()
{
    for(int i=0;i<MAXN;i++)
      for(int j=0;j<2;j++)
        f[i][j]=-1;
    f[0][0]=0;
    for(int i=0;i<K;i++)
      for(int j=0;j<2;j++)
    {
        if(f[i][j]==-1)continue;
        if(j==1)
        {
            pd(f[i+1][0],f[i][j]+even[i+1]);
            pd(f[i+1][1],f[i][j]+odd[i+1]);
        }
        else
        {
             pd(f[i+1][1],f[i][j]+even[i+1]);
            pd(f[i+1][0],f[i][j]+odd[i+1]);
        }
    }
}

int main(){
    freopen("in.cpp","r",stdin);
    while(~scanf("%d%d",&N,&K)){
        init();
        /*for(int i=1; i<=K; ++i){
            //printf("i=%d %d %d\n",i,even[i],odd[i]);
        }*/
        dp();
        printf("%d\n",f[K][0]);
    }
    return 0;
}
