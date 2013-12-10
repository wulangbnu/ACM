#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N=1000000+10;
int n,a[N],next[N],pre[N];
vector<int> vi[N];
bool get[N];
int id[N];
struct Point{
    int v,pos;
    Point(int _v=0,int _pos=0){
        v=_v; pos=_pos;
    }
    bool operator < (const Point &tt) const{
        return v<tt.v;
    }
};
set<Point> st;
set<Point>:: iterator it;
int find(int x){
    return pre[x]==x?x:pre[x]=find(pre[x]);
}
bool work(int i,int j){
    i=find(i);
    j=find(j);
    if(i==j) return false;
    pre[i]=j;
    return true;
}
void doit(){

    for(int i=1;i<=n;i++) pre[i]=i;
    st.clear();
    st.insert(Point(N,N));

    for(int i=1;i<=n;i++){
        it=st.lower_bound(a[i]);
        if(it->v!=N){
            int x=it->pos;
            work(a[i],a[x]);
            for(int j=next[x];j<i;j=next[j])
            if(!work(a[x],a[j])) break;
        }
        st.insert(Point(a[i],i));
    }
}
void pt(int x){
    if(get[x]) return;
    get[x]=true;
    int m=vi[x].size();
    printf("%d",m);
    for(int j=0;j<m;j++) printf(" %d",vi[x][j]);
    puts("");
}
void output(){

    for(int i=1;i<=n;i++)  vi[i].clear();
    for(int i=1;i<=n;i++)  vi[find(i)].push_back(i);

    int cnt=0;
    for(int i=1;i<=n;i++) if(vi[i].size()>0) cnt++;
    printf("%d\n",cnt);

    memset(get,false,sizeof(get));
    for(int i=1;i<=n;i++) pt(find(i));

}
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[n+1]=N;
        for(int i=n;i>=1;i--){
            int j=i+1;
            while(a[j]<a[i]) j=next[j];
            next[i]=j;
        }
        //for(int i=1;i<=n;i++) printf("%d %d\n",i,next[i]);
        doit();
        output();
    }
    return 0;
}
