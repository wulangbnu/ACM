#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N=50+10;
char ss[N][100];
int main(){
    //freopen("in.cpp","r",stdin);
    int n,m,q;
    while(scanf("%d",&n)+1){
        getchar();
        for(int i=1;i<=n;i++) gets(ss[i]);
        cin>>m;
        while(m--){
            cin>>q;
            if(q<1||q>n) printf("Rule %d: No such rule\n",q);
            else printf("Rule %d: %s\n",q,ss[q]);
        }
    }
    return 0;
}
