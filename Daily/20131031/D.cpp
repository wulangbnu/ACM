//dwarf.in
//dwarf.out
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N=10000+10;
const ll INF=1ll<<50;
typedef pair<int,int> pii;
int n,m,d[N];
vector<pii> vp[N];
bool inq[N];
void spfa(){
    queue<int> q;
    memset(inq,true,sizeof(inq));
    for(int i=1;i<=n;i++) q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=false;
        for(int i=0;i<vp[x].size();i++){
            int y=vp[x][i].first;
            int w=d[vp[x][i].second];
            if(d[x]+w<d[y]){
                d[y]=d[x]+w;
                if(!inq[y]){
                    q.push(y);
                    inq[y]=true;
                }
            }
        }
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    freopen("dwarf.in","r",stdin);
    freopen("dwarf.out","w",stdout);
    while(scanf("%d%d",&n,&m)+1){
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        for(int i=1;i<=n;i++) vp[i].clear();
        while(m--){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            vp[j].push_back(make_pair(i,k));
            vp[k].push_back(make_pair(i,j));
        }
        spfa();
        printf("%d\n",d[1]);
    }
    return 0;
}
