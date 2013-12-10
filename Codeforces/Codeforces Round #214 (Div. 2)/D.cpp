#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000+10;
const int M=10000+10;
const int INF=1000000+10;
int u[M],v[M],l[M],r[M];
int first[N],next[M];
int n,m;
bool get[N];
int a[M];
inline void init(){
    memset(first,-1,sizeof(first));
}
inline void insert(int e,int f){
    next[e]=first[f]; first[f]=e;
}
void dfs(int x){
    if(get[n]) return;
    if(get[x]) return;
    get[x]=true;
    for(int i=first[x];i+1;i=next[i]) dfs(v[i]);
}
bool check(int x,int y){
    init();
    for(int i=1;i<=2*m;i++){
        if(l[i]<=x&&y<=r[i]){
            insert(i,u[i]);
        }
    }
    memset(get,false,sizeof(get));
    dfs(1);
    return get[n];
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    while(scanf("%d%d",&n,&m)==2){
        int cnt=0;
        for(int i=1;i<=m;i++){
          scanf("%d%d%d%d",&u[i],&v[i],&l[i],&r[i]);
          a[cnt++]=l[i];
          a[cnt++]=r[i];
        }

        for(int i=m+1;i<=2*m;i++){
            u[i]=v[i-m]; v[i]=u[i-m]; l[i]=l[i-m]; r[i]=r[i-m];
        }

        int ans=0;
//        for(int i=1;i<=m;i++){
//            if(r[i]-l[i]+1<=ans) continue;
//            if(check(l[i],r[i])) ans=max(ans,r[i]-l[i]+1);
//        }

        sort(a,a+cnt);
        cnt=unique(a,a+cnt)-a;
//        for(int i=0;i<cnt;i++){
//            int val=a[i];
//            int x=val, y=INF;
//            while(x<y){
//                int mid=(x+y+1)>>1;
//                if(check(val,mid)){
//                   x=mid;
//                   ans=max(ans,mid-val+1);
//                }
//                else y=mid-1;
//            }
//            if(check(val,x)) ans=max(ans,x-val+1);
//        }

        int x=0, y=cnt-1;
        while(x<=y){
            if(check(a[x],a[y])) break;
            if(check(a[x],a[y-1])) y--;
            else if(check(a[x+1],a[y])) x++;
            else {x++;y--;}
        }
        ans=max(ans,a[y]-a[x]+1);

        if(ans==0) puts("Nice work, Dima!");
        else printf("%d\n",ans);
    }
    return 0;
}
