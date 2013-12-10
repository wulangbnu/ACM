#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=50000+10;
ll a[10],ans[10];
ll b[N];
char str[N][8];
int n;
int doit(char ch) {
    if(ch>='0'&&ch<='9') return ch-'0'+0;
    if(ch>='A'&&ch<='Z') return ch-'A'+10;
    if(ch>='a'&&ch<='z') return ch-'a'+36;
}
void work1() {

    for(int i=0; i<=5; i++) a[i]=0;

    for(int cnt,tot,i=0; i<(1<<5)-1; i++) {
        cnt=0;
        for(int j=0; j<5; j++) if((1<<j)&i) cnt++;

        for(int k=0; k<n; k++) {
            ll tmp=0;
            for(int j=0; j<5; j++) if(!((1<<j)&i)) tmp+=(1ll<<(j<<3))*str[k][j];
            b[k]=tmp;
        }

        sort(b,b+n);
        ll pre=-1;
        ll tmp=0;
        for(int j=0;j<n;j++){
            if(b[j]==pre) a[cnt]+=++tmp;
            else {
                pre=b[j];
                tmp=0;
            }
        }
    }
    a[5]=(ll)n*(ll)(n-1)/2;
    //for(int i=0;i<=5;i++) printf("%lld ",a[i]); puts("");
}
void work2() {
    ans[0]=a[0];
    ans[1]=a[1]-5*ans[0];
    ans[2]=a[2]-10*ans[0]-4*ans[1];
    ans[3]=a[3]-10*ans[0]-6*ans[1]-3*ans[2];
    ans[4]=a[4]-5*ans[0]-4*ans[1]-3*ans[2]-2*ans[3];
    ans[5]=a[5]-ans[0]-ans[1]-ans[2]-ans[3]-ans[4];
    for(int i=0; i<=5; i++)
        printf("%lld%c",ans[i],i==5?'\n':' ');
}
int main() {
    freopen("H.in.cpp","r",stdin);
    while(scanf("%d",&n)+1) {
        for(int i=0; i<n; i++) {
            scanf("%s",str[i]);
            for(int j=0; j<5; j++) str[i][j]=doit(str[i][j]);
        }
        work1();
        work2();
    }
    return 0;
}
