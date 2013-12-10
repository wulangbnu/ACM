#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=200000+10;
const ll M=N;
ll u[M],v[M],w[M],first[N],next[M],e;
ll pos[N],depth[N],rmq[N][20],sum[N],tot;
void init(){
    memset(first,-1,sizeof(first));
    e=0;
    tot=0;
}
void insert(int f,int t,ll val){
    u[e]=f; v[e]=t; w[e]=val;
    next[e]=first[f]; first[f]=e++;
}
void dfs(int x,int fa,int deep,ll dist){
    depth[x]=deep;
    sum[x]=dist;
    pos[x]=tot;
    rmq[tot++][0]=x;
    for(int i=first[x];i+1;i=next[i]){
        int y=v[i];
        if(y==fa) continue;
        dfs(y,x,deep+1,dist+w[i]);
        rmq[tot++][0]=x;
    }
}
void RMQ(){
    for(int j=1;(1<<j)<=tot;j++)
    for(int i=0;i+(1<<j)-1<=tot;i++){
        int x=rmq[i][j-1], y=rmq[i+(1<<(j-1))][j-1];
        rmq[i][j]=depth[x]<depth[y]?x:y;
    }
}
ll LCA(int i,int j){
    int x=pos[i], y=pos[j];
    if(x>y) swap(x,y);
    int k=log2(y-x+1.0)+(1e-8);
    x=rmq[x][k];
    y=rmq[y+1-(1<<k)][k];
    int fa=depth[x]<depth[y]?x:y;
    return sum[i]+sum[j]-2*sum[fa];
}
int main(){
    //freopen("in.cpp","r",stdin);
    int n;
    while(scanf("%d",&n)&&n){
        init();
        for(int i=1,j,k;i<n;i++){
            scanf("%d%d",&j,&k);
            insert(i,j,k);
            insert(j,i,k);
        }
        dfs(0,-1,0,0);
        RMQ();
        int m;
        scanf("%d",&m);
        for(int re=1;re<=m;re++){
            int i,j;
            scanf("%d%d",&i,&j);
            printf("%lld%c",LCA(i,j),re==m?'\n':' ');
        }
    }
    return 0;
}
