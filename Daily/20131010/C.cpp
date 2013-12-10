#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int INF=0x7fffffff;
const int N=1000000+1;
const int bit=7;
const int M=4;
int a[N][M],b[N][M],n,m;
void RMQ(){
    for(int j=1;(1<<bit*j)<=n;j++)
    for(int i=1;i+(1<<bit*j)-1<=n;i++){
        a[i][j]=a[i][j-1];
        b[i][j]=b[i][j-1];
        for(int k=i;k+(1<<bit*(j-1))-1<=n;k+=1<<bit*(j-1)){
            a[i][j]=max(a[i][j],a[k][j-1]);
            b[i][j]=min(b[i][j],b[k][j-1]);
        }
    }
}
int query(int x,int y,int a[][M],int type){
    int k=log(y-x+1.0)/log(1<<bit)+(1e-8);
    int ans=a[y-(1<<bit*k)+1][k];
    if(!type){
        for(int i=x;i+(1<<bit*k)-1<=y;i+=(1<<bit*k)) ans=max(ans,a[i][k]);
    }else{
        for(int i=x;i+(1<<bit*k)-1<=y;i+=(1<<bit*k)) ans=min(ans,a[i][k]);
    }
    return ans;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)+1){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i][0]);
            b[i][0]=a[i][0];
        }
        RMQ();
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x,y,a,0)-query(x,y,b,1));
        }
    }
    return 0;
}
