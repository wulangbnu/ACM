#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void doit(string s1,string s2){
    if(s1.size()<=0) return;
    int x=s2.find(s1[0]);
    doit(s1.substr(1,x),s2.substr(0,x));
    doit(s1.substr(x+1),s2.substr(x+1));
    printf("%c",s1[0]);
}
int main(){
    //freopen("in.cpp","r",stdin);
    string s1,s2;
    while(cin>>s1>>s2){
        doit(s1,s2);
        puts("");
    }
    return 0;
}
