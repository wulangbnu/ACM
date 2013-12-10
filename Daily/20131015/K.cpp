#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N=200000+10;
const int M=5000000+10;
int u[M],v[M],first[N],next[M],e;
int g[N],dfn[N],low[N],stk[N],scc,cnt,top;
int a[N],b[N],c[N],in[N],n,m;
vector<int> left[N],right[N];
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){
        x=min(_x,_y);
        y=max(_x,_y);
    }
    bool operator <(const Point &tt) const{
        if(x!=tt.x) return x<tt.x;
        return y<tt.y;
    }
};
set<Point> st;

void init(){
    memset(first,-1,sizeof(first));
    e=0;
    memset(dfn,-1,sizeof(dfn));
    scc=cnt=top=0;
}
void insert(int f,int t){
    u[e]=f; v[e]=t;
    next[e]=first[f]; first[f]=e++;
}
void Tarjan(int x){
    dfn[x]=low[x]=cnt++;
    stk[top++]=x;
    for(int i=first[x];i+1;i=next[i]){
        int y=v[i];
        if(dfn[y]==-1) Tarjan(y);
        low[x]=min(low[x],low[y]);
    }
    if(low[x]==dfn[x]){
        int tmp;
        do{
            tmp=stk[--top];
            g[tmp]=scc;
            low[tmp]=N;
        }while(tmp!=x);
        scc++;
    }
}
bool input(){
    int re=n;
    n=0;
    st.clear();
    memset(in,0,sizeof(in));
    for(int i=1;i<=re;i++){
        scanf("%d%d",&a[n+1],&b[n+1]);
        if(st.count(Point(a[n+1],b[n+1]))) continue;
        st.insert(Point(a[n+1],b[n+1]));
        ++n;
    }

    int tot=0;
    for(int i=1;i<=n;i++){
        c[tot++]=a[i];
        c[tot++]=b[i];
    }
    sort(c,c+tot);
    tot=unique(c,c+tot)-c;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(c,c+tot,a[i])-c+1;
        b[i]=lower_bound(c,c+tot,b[i])-c+1;
    }

    for(int i=1;i<=n;i++){
        in[a[i]]++;
        in[b[i]]++;
    }

    int ff=0;
    for(int i=1;i<=tot;i++){
        if(in[i]>2) return false;
        if(in[i]<2) ff++;
    }

    for(int i=1;i<=tot;i++){
        left[i].clear();
        right[i].clear();
    }
    if(m==tot||n==0) return true;
    else return ff>=2;
}
void doit(int x,int y){
    int xx=x+n,yy=y+n;
    if(x>n) xx=x-n;
    if(y>n) yy=y-n;
    insert(x,yy);
    insert(y,xx);
}
void work(int x,int y,int id){
    for(int i=0;i<right[x].size();i++) doit(id,right[x][i]);
    for(int i=0;i<left[y].size();i++)  doit(id,left[y][i]);
    right[x].push_back(id);
    left[y].push_back(id);
    //printf("~~ %d %d %d\n",x,y,id);
}
void add_edge(){

    for(int i=1;i<=n;i++){
        work(a[i],b[i],i);
        work(b[i],a[i],i+n);
    }
}
bool check(){
    for(int i=1;i<=2*n;i++)
    if(dfn[i]==-1) Tarjan(i);
    for(int i=1;i<=n;i++)
    if(g[i]==g[i+n]) return false;
    return true;
}
int main(){
    //freopen("K.in.cpp","r",stdin);
    while(scanf("%d%d",&m,&n)&&(n+m)){
        init();
        if(!input()){
            puts("N");
            continue;
        }
        add_edge();
        if(check()) puts("Y");
        else puts("N");
    }
    return 0;
}
