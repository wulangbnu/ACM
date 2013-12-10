#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double EPS=1e-8;
int a,m,s;
char str[10000];
double r(int a,int m,int &s){
    double val = s % m / double(m);
    s = ( a * s + 1 ) % m;
    return val;
}
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d",&a,&m,&s)+1){
        gets(str);
        while(gets(str)){
            for(int i=0;str[i];i++){
                if(str[i]<0x20||str[i]>0x7e) printf("%c",str[i]);
                else {
                    char c=str[i],x;
                    x=( (c - 32) + int( ceil( 95 - r(a,m,s)*95)+EPS ) )  % 95 + 32;
                    printf("%c",x);
                }
            }
            puts("");
        }
    }
    return 0;
}
