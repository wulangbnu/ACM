#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=20000+10;
vector<int> adj[N];
int n,sum[N],d[N];
void dfs(int x,int fa){
    sum[x]=1;
    d[x]=-1;
    for(int i=0;i<adj[x].size();i++){
        int y=adj[x][i];
        if(y==fa) continue;
        dfs(y,x);
        sum[x]+=sum[y];
        d[x]=max(d[x],sum[y]);
    }
    d[x]=max(d[x],n-sum[x]);
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=n-1;i++){
            int j,k;
            cin>>j>>k;
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        dfs(1,-1);
        int ans=N,x;
        for(int i=1;i<=n;i++)
        if(d[i]<ans) ans=d[x=i];
        cout<<x<<" "<<ans<<endl;
    }
    return 0;
}

