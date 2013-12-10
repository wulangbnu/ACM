#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N=1000000+10;
int a[2][N/8][19],v[N],n,m;
inline int F(int x,int y,int type){
    if(!type) return max(x,y);
    else return min(x,y);
}
void RMQ(int a[][19],int n,int type){
    for(int j=1;(1<<j)<=n;j++)
    for(int i=0;i+(1<<j)-1<n;i++)
    a[i][j]=F(a[i][j-1],a[i+(1<<(j-1))][j-1],type);
}
int query(int a[][19],int i,int j,int type){
    int k=log2(j-i+1)+(1e-8);
    return F(a[i][k],a[j-(1<<k)+1][k],type);
}
int doit(int x,int y,int type){
    int xx=(x>>3)+1, yy=(y>>3)-1;
    int ret=v[x];
    for(int i=x;i<=y&&i<=xx<<3;i++) ret=F(ret,v[i],type);
    for(int i=y;i>=x&&i>=yy<<3;i--) ret=F(ret,v[i],type);
    if(xx<=yy) ret=F(ret,query(a[type],xx,yy,type),type);
    return ret;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)+1){
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        for(int i=0;i<n;i+=8){
            a[0][i>>3][0]=a[1][i>>3][0]=v[i];
            for(int j=i+1;j<n&&j<i+8;j++){
                a[0][i>>3][0]=max(a[0][i>>3][0],v[j]);
                a[1][i>>3][0]=min(a[1][i>>3][0],v[j]);
            }
        }

        RMQ(a[0],(n>>3)+1,0);
        RMQ(a[1],(n>>3)+1,1);

        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            x--; y--;
            printf("%d\n",doit(x,y,0)-doit(x,y,1));
        }
    }
    return 0;
}
