#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=20000+10;
const int M=50000+10;
int u[M],v[M],first[N],next[M],e;
int g[N],dfn[N],low[N],stk[N],scc,cnt,top;
int n,m,in[N],out[N];
void init(){
    memset(first,-1,sizeof(first));
    memset(dfn,-1,sizeof(dfn));
    e=0;
    scc=cnt=top=0;
}
void insert(int f,int t){
    u[e]=f; v[e]=t;
    next[e]=first[f]; first[f]=e++;
}
void Tarjan(int x,int fa){
    dfn[x]=low[x]=cnt++;
    stk[top++]=x;
    for(int i=first[x];i+1;i=next[i]){
        if(dfn[v[i]]==-1) Tarjan(v[i],x);
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
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&n,&m);
        while(m--){
            int i,j;
            scanf("%d%d",&i,&j);
            insert(i,j);
        }
        for(int i=1;i<=n;i++)
        if(dfn[i]==-1) Tarjan(i,-1);

        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        //for(int i=1;i<n;i++) printf("!!! %d %d\n",i,g[i]);
        for(int i=0;i<e;i++){
            int x=g[u[i]], y=g[v[i]];
            if(x==y) continue;
            in[x]++;
            out[y]++;
        }
        int ans[2]={0};
        for(int i=0;i<scc;i++){
            if(in[i]==0) ans[0]++;
            if(out[i]==0) ans[1]++;
        }
        if(scc==1) printf("0\n");
        else{
            printf("%d\n",max(ans[0],ans[1]));
        }
    }
    return 0;
}
