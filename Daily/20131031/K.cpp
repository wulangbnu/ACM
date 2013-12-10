#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000000+10;
int m,n;
int k1,k2;
int a,b,c,d;
void doit(int &a,int &m,int &k,int &c){
    m=a+1;
    if(a&1) k=2;
    else k=1;
}
void solve(){
    while(b*m!=c*n){
        if(b*m<c*n) m+=k1;
        else        n+=k2;
    }
}
int get[N];
void output(int m,int a,int base){
    memset(get,0,sizeof(get));
    int i=1,j=1;
    for(i=1;i<=m;i++){
        if(get[i]==a) continue;
        for(;;j++){
            if(j==m+1) j=1;
            if(get[j]==a||i==j) continue;
            printf("%d %d\n",i+base,j+base);
            ++get[j];
            if(++get[i]==a) break;
        }
    }
}
void work(int m,int n,int b,int c){
    memset(get,0,sizeof(get));
    int i=1,j=1;
    for(i=1;i<=m;i++){
        while(get[j]==c) j++;
        for(int k=j;k<j+b;k++){
            printf("%d %d\n",i,k+m);
            get[k]++;
        }
    }
}
void test(){
    output(6,2,0);
}
int main(){
    freopen("in.cpp","r",stdin);
    //freopen("kids.in","r",stdin);
    //freopen("kids.out","w",stdout);

    //test();return 0;

    while(scanf("%d%d%d%d",&a,&b,&c,&d)+1){
        doit(a,m,k1,c);
        doit(d,n,k2,b);

        solve();
        printf("%d %d\n",m,n);
        //printf("~~ %d %d\n",m,a);

        output(m,a,0);
        //work(m,n,b,c);
        //output(n,d,m);
    }
    return 0;
}
