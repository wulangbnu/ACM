#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
const int M=100000+10;
int m,n;
int k1,k2;
int a,b,c,d;
void doit(int &a,int &m,int &k,int &c) {
    m=a+1;
    if(a&1) k=2;
    else k=1;
    while(m<c) m+=k;
}
void solve() {
    while(b*m!=c*n) {
        if(b*m<c*n) m+=k1;
        else        n+=k2;
    }
}

void out2(int m,int n,int b,int c) {
    int i=1,j=1;
    for(i=1; i<=m; i++) {
        for(int k=0; k<b; k++) {
            printf("%d %d\n",i,j+m);
            j=j%n+1;
        }
    }
}

void output(int m,int a,int base) {
    //printf("~~~ %d %d\n",m,a);
    for (int i=1;i<=m;i++)
    for (int j=i+1;j<=i+(a/2);j++)
    printf("%d %d\n", i+base,(j-1)% m+1+base);

    if (a&1) {
        for (int i=1;i<=m/2;i++) printf("%d %d\n",i+base,m/2+i+base);
    }
}
int main() {
    //freopen("in.cpp","r",stdin);
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);

    while(scanf("%d%d%d%d",&a,&b,&c,&d)+1) {
        doit(a,m,k1,c);
        doit(d,n,k2,b);

        solve();
        printf("%d %d\n",m,n);
        output(m,a,0);
        out2(m,n,b,c);
        output(n,d,m);
    }
    return 0;
}
