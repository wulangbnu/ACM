#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
const ll P=23;
const ll N=400000+10;
ll seed[N];
int a[N],b[N],c[N],n,m,p;
vector<int> ans;
void init(){
    seed[0]=1;
    for(int i=1;i<N;i++) seed[i]=seed[i-1]*P;
}
void doit(int s,ll v,int cnt){
    int tot=0,ret=0;
    if(s+(m-1)*(ll)p>n) return;
    ll x=0;
    for(int i=1;i<=m;i++) x+=seed[ a[s+(i-1)*p] ];

    for(int i=m;s+(i-1)*(ll)p<=n;i++){
        if(x==v) ans.push_back(s+(i-m)*p);
        x-=seed[ a[s+(i-m)*p] ];
        x+=seed[ a[s+i*p] ];
    }
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    init();
    while(scanf("%d%d%d",&n,&m,&p)==3){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);

        int cnt=0;
        for(int i=1;i<=n;i++) c[cnt++]=a[i];
        for(int i=1;i<=m;i++) c[cnt++]=b[i];
        sort(c,c+cnt);
        unique(c,c+cnt);
        for(int i=1;i<=n;i++) a[i]=lower_bound(c,c+cnt,a[i])-c+1;
        for(int i=1;i<=m;i++) b[i]=lower_bound(c,c+cnt,b[i])-c+1;

        ll v=0;
        for(int i=1;i<=m;i++) v+=seed[b[i]];

        ans.clear();
        for(int i=1;i<=p;i++) doit(i,v,cnt);

        sort(ans.begin(),ans.end());
        int sz=ans.size();
        printf("%d\n",sz);
        for(int i=0;i<sz;i++)
        printf("%d%c",ans[i],i==sz-1?'\n':' ');
    }
    return 0;
}
