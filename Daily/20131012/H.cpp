#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
const int N=100+10;
const int M=N*N;
int u[M],v[M],first[N],next[M],e;
int in[N],ans,n;
bool get[M];
vector<int> path[M];
void init(){
    memset(first,-1,sizeof(first));
    memset(in,0,sizeof(in));
    memset(get,false,sizeof(get));
    e=0;
    ans=0;
}
void insert(int f,int t){
    u[e]=f; v[e]=t;
    next[e]=first[f]; first[f]=e++;
}
bool dfs(int x,bool tag,int id){

    for(int i=first[x];i+1;i=next[i]){
        int y=v[i];
        if(get[i]&&dfs(y,tag,id)){
            path[id].push_back(x);
            return true;
        }
        if(!get[i]&&dfs(y,true,id)){
            get[i]=true;
            path[id].push_back(x);
            return true;
        }
    }

    if(first[x]==-1){
        if(tag) path[id].push_back(x);
        return tag;
    }
    return false;
}

void solve(){

    memset(get,false,sizeof(get));
    for(int i=0;i<M;i++) path[i].clear();

    int x=1;
    int f=1;
    while(f){
        for(int x=1;x<=n;x++){
            if(in[x]) continue;
            if(!dfs(x,false,ans)) f=0;
            else ans++;
        }
    }

    printf("%d\n",ans);

    for(int i=0;i<ans;i++)
    for(int j=path[i].size()-1;j>=0;j--)
    printf("%d%c",path[i][j],j==0?'\n':' ');

}
int main(){

    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        init();
        for(int j,k,i=1;i<=n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&j);
                insert(i,j);
                in[j]++;
            }
        }

        solve();
    }
    return 0;
}
