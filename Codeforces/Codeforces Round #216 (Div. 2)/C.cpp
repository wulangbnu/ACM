#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=100000+10;
vector<int> adj[N];
int n;
bool tag[N];
bool dfs(int x,int fa,int val){
    tag[x]=(val==2);
    bool ret=false;
    for(int i=0;i<adj[x].size();i+=2){
        int y=adj[x][i],v=adj[x][i+1];
        if(y==fa) continue;
        ret|=dfs(y,x,v);
    }
    if(ret) tag[x]=false;
    //printf("%d %d %d %d\n",x,fa,val,tag[x]);
    return ret|tag[x];
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=n-1;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(b);
            adj[a].push_back(c);
            adj[b].push_back(a);
            adj[b].push_back(c);
        }

        memset(tag,false,sizeof(tag));

        dfs(1,-1,1);
        int ans=0;
        for(int i=1;i<=n;i++) if(tag[i]) ans++;
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
        if(tag[i]) printf("%d%c",i,--ans==0?'\n':' ');
    }
    return 0;
}
