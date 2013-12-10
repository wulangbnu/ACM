#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=20000+10;
const int M=40000+10;
int u[M],v[M],first[M],next[M],e;
int g[N],dfn[N],low[N],stk[N],scc,top,cnt;
int n,m,a[N];
void init(){
    memset(first,-1,sizeof(first));
    e=0;
    memset(dfn,-1,sizeof(dfn));
    scc=cnt=top=0;
}
void insert(int f,int t){
    u[e]=f; v[e]=t;
    next[e]=first[f]; first[f]=e++;
}
void Tarjan(int x){
    dfn[x]=low[x]=cnt++;
    stk[top++]=x;
    for(int i=first[x];i+1;i=next[i]){
        if(dfn[v[i]]==-1) Tarjan(v[i]);
        low[x]=min(low[x],low[v[i]]);
    }
    if(low[x]==dfn[x]){
        int tmp;
        do{
            tmp=stk[--top];
            g[tmp]=scc;
            low[tmp]=N;
        }while(tmp!=x);
        scc++;
    }
}
void conflict(int x,int y){
    int i=x-n,j=y-n;
    if(x<n) i=n+x;
    if(y<n) j=n+y;
    insert(x,j);
    insert(y,i);
}
void doit(int i,int j,int k){
    if(k==0){
        if(a[i]!=a[j]) conflict(i,j);
        if(a[i]!=a[j+n]) conflict(i,j+n);
        if(a[i+n]!=a[j]) conflict(i+n,j);
        if(a[i+n]!=a[j+n]) conflict(i+n,j+n);
    }else{
        if(a[i]==a[j]) conflict(i,j);
        if(a[i]==a[j+n]) conflict(i,j+n);
        if(a[i+n]==a[j]) conflict(i+n,j);
        if(a[i+n]==a[j+n]) conflict(i+n,j+n);
    }
}
bool check(){
    for(int i=0;i<n;i++)
    if(g[i]==g[i+n]) return false;
    return true;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i+n]=a[i]+1;
            if(a[i+n]==4) a[i+n]=1;
        }
        while(m--){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            doit(--i,--j,k);
        }

        for(int i=0;i<2*n;i++)
        if(dfn[i]==-1) Tarjan(i);

//        for(int i=0;i<n;i++)
//        printf("%d %d\n",g[i],g[i+n]);

        printf("Case #%d: ",cas++);
        if(check()) puts("yes");
        else puts("no");
    }
    return 0;
}
