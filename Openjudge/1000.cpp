#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N=1000+10;
int a[N][N],n,m,ans;

inline int lowbit(int i){
    return i&-i;
}
void ad(int x,int y,int val){
    for(int i=x;i<=n;i+=lowbit(i))
    for(int j=y;j<=n;j+=lowbit(j))
    a[i][j]+=val;
}
void add(int x1,int y1,int x2,int y2,int val){
    ad(x1,y1,val);
    ad(x2+1,y1,-val);
    ad(x1,y2+1,-val);
    ad(x2+1,y2+1,val);
}
int sum(int x,int y){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
    for(int j=y;j>0;j-=lowbit(j))
    ret+=a[i][j];
    return ret;
}

bool solve(){
    ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i+m-1<=n&&j+m-1<=n){
            if(sum(i,j)&1) continue;
            ans++;
            add(i,j,i+m-1,j+m-1,1);
        }else{
            if(sum(i,j)==0) return false;
        }
    }
    return true;
}
void getint(int &x){
    x=0;
    char ch=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)+1){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int x;
            getint(x);
            if(x) add(i,j,i,j,x);
        }
        if(solve()) printf("%d\n",ans);
        else puts("-1");
    }
    return 0;
}
