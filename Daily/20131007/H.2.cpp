#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N=200000+10;
const ll INF=(1ll<<40);
bool get[N];
vector<int> adj[N];
struct Point{
    int a,b;
    ll v;
    void input(int id){
        int cnt,i;
        scanf("%d%d%d",&a,&b,&cnt);
        adj[id].clear();
        v=-1;
        for(int j=0;j<cnt;j++){
            scanf("%d",&i);
            adj[id].push_back(i);
        }
    }
}p[N];
int n;
ll dfs(int x){
    if(p[x].v!=-1) return p[x].v;
    if(get[x]) return p[x].b;
    get[x]=true;

    if(int(adj[x].size())==0) p[x].v=p[x].b;
    else{
        ll ret=p[x].a;
        for(int i=0;i<(int)(adj[x].size());i++)
        ret+=dfs(adj[x][i]);
        p[x].v=min(ret,(ll)p[x].b);
    }
    return p[x].v;
}
int main(){

    freopen("in.cpp","r",stdin);

    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) p[i].input(i);
        ll y=INF;
        for(int i=1;i<=n;i++) y=min(y,(ll)p[i].b);
        for(int i=1;i<=n;i++){
            if(y==p[i].b) p[i].v=p[i].b;
        }
        for(int i=1;i<=n;i++) get[i]=false;
        printf("%lld\n",dfs(1));
    }

    return 0;
}
