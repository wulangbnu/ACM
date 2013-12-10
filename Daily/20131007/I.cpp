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
            for(int j=it->pos;j<i;j=next[j])
            if(!work(a[i],a[j])) break;
        }
        st.insert(Point(a[i],i));
    }
}
void output(){
    memset(get,false,sizeof(get));
    for(int i=1;i<=n;i++) get[find(i)]=true;
    int cnt=0;
    for(int i=1;i<=n;i++) if(get[i]) id[i]=cnt++;

    for(int i=0;i<cnt;i++) vi[i].clear();
    for(int i=1;i<=n;i++) vi[id[find(i)]].push_back(i);
    sort(vi,vi+cnt);

    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        int m=vi[i].size();
        if(m==0) continue;
        printf("%d",m);
        for(int j=0;j<m;j++) printf(" %d",vi[i][j]);
        puts("");
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
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
