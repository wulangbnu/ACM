#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int N=300000+10;
const int M=1000000+10;
const int INF=0x3f3f3f3f;
int u[M],v[M],w[M],first[N],next[M],e;
int layer[N],n,m,c;
bool tag[N];
void init(){
    memset(first,-1,sizeof(first));
    memset(tag,false,sizeof(tag));
    e=0;
}
void insert(int f,int t,int val){
    u[e]=f; v[e]=t; w[e]=val;
    next[e]=first[f]; first[f]=e++;
}
int q[N];
int d[N];
bool inq[N];
int spfa(int s,int t){
    for(int i=1;i<=3*n;i++){
        d[i]=INF;
        inq[i]=false;
    }
    int l=0,r=0;
    d[s]=0;
    q[r++]=s;
    inq[s]=true;
    while(l!=r){
        int x=q[l++];
        if(l>=N) l=0;
        inq[x]=false;
        for(int i=first[x];i+1;i=next[i]){
            int y=v[i];
            if(d[x]+w[i]<d[y]){
                d[y]=d[x]+w[i];
                if(!inq[y]){
                    q[r++]=y;
                    if(r>=N) r=0;
                    inq[y]=true;
                }
            }
        }
    }
    if(d[t]>=INF) return -1;
    return d[t];
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d%d",&n,&m,&c);
        for(int i=1;i<=n;i++) scanf("%d",&layer[i]);
        tag[1]=tag[n]=true;
        while(m--){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            tag[i]=tag[j]=true;
            insert(i,j,k);
            insert(j,i,k);
        }
        for(int i=1;i<=n;i++){
            //if(!tag[i]) continue;
            insert(i,layer[i]+2*n,0);
            insert(layer[i]+n,i,0);
        }
        for(int i=1;i<n;i++){
            insert(i+2*n,i+1+n,c);
            insert(i+1+2*n,i+n,c);
        }
        printf("Case #%d: %d\n",cas++,spfa(1,n));
    }
    return 0;
}
