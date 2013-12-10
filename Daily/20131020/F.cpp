#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
struct Edge{
    int a,b,v;
    bool operator <(const Edge &tt) const{
        return v<tt.v;
    }
}p[N];
int pre[N],f[30],cnt,n,m;
int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}
bool cmp(Edge p1,Edge p2){
    return p1.v>p2.v;
}
void init(){
    int x=1, y=1;
    f[cnt++]=1;
    while(y<N){
        y=x+y;
        x=y-x;
        f[cnt++]=y;
    }
//    for(int i=0;i<cnt;i++)
//    printf("%d\n",f[i]);
}
int doit(){
    for(int i=1;i<=n;i++) pre[i]=i;
    int ret=0;
    for(int i=0;i<m;i++){
        int a=find(p[i].a), b=find(p[i].b);
        if(a==b) continue;
        ret+=p[i].v;
        pre[a]=b;
    }
    return ret;
}
bool check(int x,int y){
    for(int i=0;i<cnt;i++)
    if(f[i]>=x&&f[i]<=y) return true;
    return false;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=0;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].v);
        }
        sort(p,p+m);
        int x=doit();
        sort(p,p+m,cmp);
        int y=doit();
        printf("Case #%d: ",++cas);
        if(check(x,y)) puts("Yes");
        else puts("No");
    }
    return 0;
}
