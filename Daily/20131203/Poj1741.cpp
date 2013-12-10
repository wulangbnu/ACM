#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define C(a,x) memset(a,x,sizeof(a));
using namespace std;
const int N=10000+10;
vector<int> adj[N];
bool tag[N];
int n,m,sum[N],d[N],depth[N],ans;
void dfs(int x,int fa,vector<int> &vs){
    sum[x]=1;
    d[x]=-1;
    vs.push_back(x);
    for(int i=0;i<adj[x].size();i+=2){
        int y=adj[x][i];
        if(y==fa||tag[y]) continue;
        dfs(y,x,vs);
        sum[x]+=sum[y];
        d[x]=max(d[x],sum[y]);
    }
}
void dfs(int x,int fa){
    for(int i=0;i<adj[x].size();i+=2){
        int y=adj[x][i];
        if(y==fa||tag[y]) continue;
        depth[y]=depth[x]+adj[x][i+1];
        dfs(y,x);
    }
}
bool cmp(const int &x,const int &y){
    return depth[x]<depth[y];
}
inline int work(vector<int> &vs){
    sort(vs.begin(),vs.end(),cmp);
    int l=0,r=int(vs.size())-1,ret=0;
    while(l<r){
        if(depth[vs[l]]+depth[vs[r]]<=m){
            ret+=r-l;
            l++;
        }else r--;
    }
    return ret;
}
void doit(int x,int type=1){

    vector<int> vs;
    dfs(x,-1,vs);
    int n=int(vs.size());
    if(n==1) return;
    if(type) ans-=work(vs);

    int root,tmp=N;
    for(int i=0;i<n;i++){
        int x=vs[i];
        d[x]=max(d[x],n-sum[x]);
        if(d[x]<tmp) tmp=d[root=x];
    }

    tag[root]=true;
    depth[root]=0;
    dfs(root,-1);
    ans+=work(vs);

    //cout<<root<<" "<<ans<<endl;

    for(int i=0;i<adj[root].size();i+=2){
        int y=adj[root][i];
        if(tag[y]) continue;
        doit(y);
    }
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)&&n+m){
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=n-1;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(b); adj[a].push_back(c);
            adj[b].push_back(a); adj[b].push_back(c);
        }
        C(tag,false);
        ans=0;
        doit(1,0);
        printf("%d\n",ans);
    }
    return 0;
}

