#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=2000+10;
const int M=100000+10;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
vector<pii> vp[10];
int n,m,k,s,a[M],d[N][2];
int doit(int x,int y){
    for(int i=1;i<=k;i++){
        d[i][0]=-INF;
        d[i][1]=INF;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<vp[i].size();j++){
            int val=x*(vp[i][j].first)+y*(vp[i][j].second);
            d[i][0]=max(d[i][0],val);
            d[i][1]=min(d[i][1],val);
        }
    }
    int ret=-INF;
    for(int i=1;i<s;i++){
        int v1=a[i],v2=a[i+1];
        ret=max(ret,d[v1][0]-d[v2][1]);
        ret=max(ret,d[v2][0]-d[v1][1]);
    }
    return ret;
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    while(scanf("%d%d%d%d",&n,&m,&k,&s)==4){
        for(int i=1;i<=9;i++) vp[i].clear();
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int v;
            scanf("%d",&v);
            vp[v].push_back(make_pair(i,j));
        }
        for(int i=1;i<=s;i++) scanf("%d",&a[i]);

        int ans=doit(1,1);
        ans=max(ans,doit(1,-1));
        ans=max(ans,doit(-1,1));
        ans=max(ans,doit(-1,-1));

        printf("%d\n",ans);
    }
    return 0;
}
