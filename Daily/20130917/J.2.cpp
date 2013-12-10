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
void init(){
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val){
    u[e]=f; v[e]=t; w[e]=val;
    next[e]=first[f]; first[f]=e++;
}
struct node{
    int x,y;
    node(){}
    node(int _x,int _y):x(_x),y(_y){}
    bool operator <(const node &tt) const{
        return y>tt.y;
    }
};
struct Heap{
    node _v[N*10];
    int size;
    void push(node a){
        _v[size++]=a;
        if(size>1) push_heap(_v,_v+size);
    }
    void pop(){
        pop_heap(_v,_v+size);
        --size;
    }
    node top(){
        return _v[0];
    }
    void init(){
        size=0;
    }
    bool empty(){
        return size==0;
    }
}hp;
int d[N];
int DJ(int s,int t){
    for(int i=0;i<=3*n;i++) d[i]=INF;
    d[s]=0;
    hp.init();
    hp.push(node(s,0));
    while(!hp.empty()){
        node p=hp.top();
        hp.pop();
        int x=p.x, y=p.y;
        if(x==t) return d[t];
        if(y!=d[x]) continue;
        for(int i=first[x];i+1;i=next[i]){
            if(d[x]+w[i]<d[v[i]]){
                d[v[i]]=d[x]+w[i];
                hp.push(node(v[i],d[v[i]]));
            }
        }
    }
    return -1;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d%d",&n,&m,&c);
        for(int i=1;i<=n;i++) scanf("%d",&layer[i]);
        while(m--){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            insert(i,j,k);
            insert(j,i,k);
        }
        for(int i=1;i<=n;i++){
            insert(i,layer[i]+2*n,0);
            insert(layer[i]+n,i,0);
        }
        for(int i=1;i<n;i++){
            insert(i+2*n,i+1+n,c);
            insert(i+1+2*n,i+n,c);
        }
        printf("Case #%d: %d\n",cas++,DJ(1,n));
    }
    return 0;
}
