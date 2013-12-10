#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=100+10;
vector<int> adj[N];
int n,m,q,ans;
int tag[N],f[N];
bool doit(int x){
    bool ret=false;
    memset(tag,0,sizeof(tag));
    memset(f,0,sizeof(f));
    tag[x]=1;
    for(int i=0;i<adj[x].size();i++) tag[adj[x][i]]=1;
    for(int i=0;i<adj[x].size();i++){
        int y=adj[x][i];
        for(int j=0;j<adj[y].size();j++){
            if(tag[adj[y][j]]) continue;
            f[adj[y][j]]++;
        }
    }
    while(1){
        bool done=true;
        for(int i=0;i<n;i++){
            if(tag[i]) continue;
            if(f[i]>=q) {
                ans++;
                ret=true;
                done=false;
                adj[x].push_back(i);
                adj[i].push_back(x);
                tag[i]=1;
                for(int j=0;j<adj[i].size();j++){
                    if(tag[adj[i][j]]) continue;
                    f[adj[i][j]]++;
                }
            }
        }
        if(done) break;
    }
    return ret;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0;i<n;i++) adj[i].clear();
        while(m--){
            int i,j;
            scanf("%d%d",&i,&j);
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        ans=0;
        while(1){
            bool done=true;
            for(int i=0;i<n;i++)
            if(doit(i)) done=false;
            if(done) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
