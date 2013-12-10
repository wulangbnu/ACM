#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int N=10000+10;
const int MOD=10001;
int x[N],n;
int cnt[N];
void doit(int x1,int x3,int x5){
    for(int a=0;a<=10000;a++){
         if((a*a%MOD*(x3-x1)%MOD+MOD)%MOD==((x5-x3)%MOD+MOD)%MOD) cnt[a]++;
    }
}
void doit2(){
    printf("%d\n",x[2]);
    printf("%d\n",x[2]);
}
bool check(int a,int b){
    vector<int> s;
    int t=x[1];
    for(int i=1;i<=2*n;i++){
        if(i&1){
            if(t!=x[(i+1)/2]) return false;
        }
        s.push_back(t);
        t=(t*a+b)%MOD;
       // printf("%d\n",i);
    }
    for(int i=1;i<s.size();i+=2){
        printf("%d\n",s[i]);
    }
    return true;
}
bool work(int a){


    for(int b=0;b<=10000;b++){
        int m=0;
        for(int i=1;i<n;i++){
            if( (a*a%MOD*x[i]+a*b+b)%MOD==x[i+1] ) m++;
            else break;
        }
        if(m==n-1&&check(a,b)) return true;
    }
    return false;
}
void doit3(){
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n-2;i++) doit(x[i],x[i+1],x[i+2]);
    for(int i=0;i<=10000;i++)
    if(cnt[i]==n-2&&work(i)) return;
}
int main(){

    //freopen("in.cpp","r",stdin);

    while(scanf("%d",&n)+1){
        for(int i=1;i<=n;i++) scanf("%d",&x[i]);
        if(n==1) printf("1\n");
        else if(n==2) doit2();
        else doit3();
    }

    return 0;
}
