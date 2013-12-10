#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
string s[]={"B", "KB", "MB","GB", "TB", "PB", "EB", "ZB", "YB"};
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=0,x;
    scanf("%d",&T);
    while(T--){
        char str[10];
        scanf("%d[%s",&x,str);
        str[strlen(str)-1]=0;
        string ss=str;
        double ans=1.0;
        int n;
        for(n=0;;n++) if(s[n]==ss) break;
        for(int i=0;i<n;i++) ans*=1000/1024.0;
        printf("Case #%d: %.2f\%\n",++cas,(1-ans)*100);
    }
    return 0;
}
