#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=1000000+10;

int n,a[maxn];
int c[maxn];
int pre[maxn],nxt[maxn];
int pnt[maxn];

vector<int>ans[maxn];

int pd(int x) {
    if(x!=pnt[x])pnt[x]=pd(pnt[x]);
    return pnt[x];
}

void init() {
    for(int i=1;i<=n;i++)ans[i].clear();
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    for(int i=1; i<=n; i++) pnt[i]=i;

    c[n]=a[n];
    for(int i=n-1; i>=1; i--) c[i]=min(c[i+1],a[i]);

    a[0]=a[n+1]=maxn;

    for(int i=1; i<=n; i++) {
        int j=i-1;
        while(a[j]<a[i]) j=pre[j];
        pre[i]=j;
    }

    for(int i=n; i>=1; i--) {
        int j=i+1;
        while(a[j]<a[i]) j=nxt[j];
        nxt[i]=j;
    }

}

void solve() {
    for(int i=1; i<=n; i++) {
        int x=pre[i];
        if(x>=1&&x<=n) {
            int px=pd(x);
            int py=pd(i);
            if(px!=py) {
                if(px<py)swap(px,py);
                pnt[px]=py;
            }
        }
        x=nxt[i];
        if(x>=1&&x<=n&&c[x]<a[i]) {
            int px=pd(x);
            int py=pd(i);
            if(px!=py) {
                if(px<py)swap(px,py);
                pnt[px]=py;
            }
        }
    }
}

void output()
{
    for(int i=1;i<=n;i++)ans[pd(i)].push_back(i);
    int ret=0;
    for(int i=1;i<=n;i++)
    if(pd(i)==i)ret++;
    printf("%d\n",ret);
    for(int i=1;i<=n;i++)
    if(pd(i)==i)
    {
        printf("%d",ans[i].size());
        for(int j=0;j<ans[i].size();j++)
        printf(" %d",ans[i][j]);
        printf("\n");
    }
}

int main() {

    //freopen("i.in.cpp","r",stdin);
    while(scanf("%d",&n)+1) {
        init();
        solve();
        output();
    }
    return 0;
}
