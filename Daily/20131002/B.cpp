#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void doit(int x){
    vector<int> s;
    s.push_back(x);
    while(x>=10){
        int y=1;
        while(x){
            y*=x%10;
            x/=10;
        }
        s.push_back(x=y);
    }
    for(int i=0;i<s.size();i++)
    printf("%d%c",s[i],i==s.size()-1?'\n':' ');
}
int main(){
    //freopen("in.txt","r",stdin);
    ///freopen("out.me.txt","w",stdout);
    int n;
    while(scanf("%d",&n)&&n) doit(n);
    return 0;
}
