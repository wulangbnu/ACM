//crazier
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N=200000+10;
const ll INF=1ll<<50;
bool get[N];
struct Point{
    int a,b;
    ll v;
    vector<int> adj;
    void input(){
        int cnt,i;
        scanf("%d%d%d",&a,&b,&cnt);
        adj.clear();
        v=-1;
        for(int j=0;j<cnt;j++){
            scanf("%d",&i);
            adj.push_back(i);
        }
    }
}p[N];
int n;
int g[N],dfn[N],low[N],stk[N],scc,cnt,top;
void init(){
    memset(dfn,-1,sizeof(dfn));
    scc=cnt=top=0;
    memset(get,false,sizeof(get));
}
void Tarjan(int x){
    dfn[x]=low[x]=cnt++;
    stk[top++]=x;
    for(int i=0;i<p[x].adj.size();i++){
        int y=p[x].adj[i];
        if(dfn[y]==-1) Tarjan(y);
        low[x]=min(low[x],low[y]);
    }
    if(low[x]==dfn[x]){
        int tmp,id,cnt=0;
        ll y=INF;
        do{
            tmp=stk[--top];
            cnt++;
            g[tmp]=scc;
            low[tmp]=N;
            if(p[tmp].b<y){
                y=p[tmp].b;
                id=tmp;
            }
        }while(tmp!=x);
        scc++;
        if(cnt>1) p[id].v=p[id].b;
    }
}
ll dfs(int x){
    if(p[x].v!=-1) return p[x].v;
    if(get[x]) return INF;
    get[x]=true;
    if(p[x].adj.size()==0) return p[x].v=p[x].b;
    ll ret=p[x].a;
    for(int i=0;i<p[x].adj.size();i++)
    ret+=dfs(p[x].adj[i]);
    ret=min(ret,(ll)p[x].b);

    return p[x].v=ret;

}
int main(){

    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        init();
        for(int i=1;i<=n;i++) p[i].input();
//        for(int i=1;i<=n;i++)
//        if(dfn[i]==-1) Tarjan(i);

        ll y=INF;

        for(int i=1;i<=n;i++) y=min(y,(ll)p[i].b);
        for(int i=1;i<=n;i++){
            if(y==p[i].b) p[i].v=p[i].b;
        }

        memset(get,false,sizeof(get));

        printf("%lld\n",dfs(1));
    }
    return 0;
}
