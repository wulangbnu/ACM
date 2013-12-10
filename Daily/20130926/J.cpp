#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=100005;
typedef long long ll;

struct P {
    int x,y;
    bool operator<(const P &a)const {
        if(x==a.x)return y<a.y;
        return x<a.x;
    }
} p[maxn];
int n,a[maxn];

int temp[maxn*2];
ll msort(int a[],int lt,int rt) {
    if(lt==rt)return 0;
    int i,j,k,m=(lt+rt)>>1;
    ll t=msort(a,lt,m);
    t+=msort(a,m+1,rt);
    i=lt;
    j=m+1;
    for(k=lt; k<=rt; ++k) {
        if(i<=m&&a[i]<=a[j]||j>rt)temp[k]=a[i++];
        else {
            temp[k]=a[j++];
            t+=m-i+1;
        }
    }
    memcpy(a+lt,temp+lt,(rt-lt+1)*sizeof(int));
    return t;
}

int main() {
    //freopen("in.cpp","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p,p+n);
    for(int i=0; i<n; i++)
        a[i]=p[i].y;
    printf("%lld\n",msort(a,0,n-1));
    return 0;
}
