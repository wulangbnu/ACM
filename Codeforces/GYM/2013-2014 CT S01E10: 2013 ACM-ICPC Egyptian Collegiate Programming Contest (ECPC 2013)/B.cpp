/**
题目大意：n个点 m条边 a到b的路径长度定义为a到b的边中边的最大权值
输出每个点到其他点路径长度最小值的和
带权并查集
**/
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int N=100000+10;
struct Edge{
    int a,b,v;
    bool operator < (const Edge &tt) const{
        return v<tt.v;
    }
}e[N];
int pre[N],fa[N],dist[N],cnt[N],n,m;
int find(int x){
    if(x==pre[x]) return x;
    int pa=find(pre[x]);
    dist[x]+=dist[pre[x]]-fa[x];  //x节点只增加父节点增加的权值
    fa[x]=dist[pa];               //更新父节点及其父节点当前权值
    return pre[x]=pa;
}
int main(){

    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    #ifndef wulang
        freopen("road.in","r",stdin);
    #endif

    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].v);
        sort(e+1,e+1+m);
        for(int i=1;i<=n;i++){
            pre[i]=i;
            dist[i]=0;
            cnt[i]=1;
        }
        for(int i=1;i<=m;i++){
            int x=find(e[i].a), y=find(e[i].b), v=e[i].v;
            if(x==y) continue;
            dist[x]+=cnt[y]*v;
            dist[y]+=cnt[x]*v;
            pre[x]=y;
            cnt[y]+=cnt[x];
            fa[x]=dist[y];
        }
        printf("Case %d:\n",++cas);
        for(int i=1;i<=n;i++){
            find(i);
            printf("%d\n",dist[i]);
        }
    }
    return  0;
}
