#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000+10;
const double EPS=1e-8;
char str[N];
int sgn(double x){
    return x<-EPS?-1:x>EPS;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%s",str)+1){
        int n=strlen(str);
        str[n]=str[0];

        int a[2]={0};
        for(int i=0;i<n;i++) a[str[i]-'0']++;

        int b[2]={0};
        for(int i=0;i<n;i++){
            if(str[i]=='1') continue;
            b[str[i+1]-'0']++;
        }

        double x=a[0]*1.0/(a[0]+a[1]);
        double y=b[0]*1.0/(b[0]+b[1]);
        if(sgn(x-y)>0) puts("ROTATE");
        else if(sgn(x-y)<0) puts("SHOOT");
        else puts("EQUAL");

    }
    return 0;
}
