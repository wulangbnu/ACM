#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=105;

int n;
char str[maxn],s[maxn];

int main(){
    //freopen("in.cpp","r",stdin);
   int T,ncase=0;
   scanf("%d",&T);
   while(T--)
   {
       scanf("%d%s",&n,str);
       strcpy(s,str);
       sort(s,s+n);
       int ret=0;
       for(int i=0;i<n;i++)
       if(s[i]!=str[i])ret++;
       printf("Case %d: %d\n",++ncase,ret);
   }
    return 0;
}
