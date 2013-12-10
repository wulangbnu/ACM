#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
const double EPS=1e-8;
const int N=1000000;
const int M=65536+10;
char str[N];
int a,m,s;
map<int,int> mp[M];
double r(int a,int m,int s){
    double val = s % m / double(m);
    //s = ( a * s + 1 ) % m;
    return val;
}
void init(){

    for(int i=0;i<M;i++) mp[i].clear();
    for(int s=0;s<m;s++)
    for(int x,c=0x20;c<=0x7e;c++){
        x=( (c - 32) + int( ceil( 95 - r(a,m,s)*95)+EPS ) )  % 95 + 32;
        mp[s][x]=c;
    }
}
int main(){
    //freopen("in.2.cpp","r",stdin);
    while(scanf("%d%d%d",&a,&m,&s)+1){
        gets(str);
        init();
        while(gets(str)){
            for(int i=0;str[i];i++){
                if(str[i]<0x20||str[i]>0x7e) printf("%c",str[i]);
                else {
                    printf("%c",mp[s][str[i]]);
                    s = ( a * s + 1 ) % m;
                }
            }
            puts("");
        }
    }
    return 0;
}
