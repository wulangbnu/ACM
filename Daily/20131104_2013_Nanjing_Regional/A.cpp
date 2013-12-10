#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s[]={"A","A-","B+","B","B-","C+","C","C-","D","D-","F"};
double v[]={4.0, 3.7, 3.3,3.0, 2.7, 2.3,2.0, 1.7,1.3, 1.0,0};
double doit(string ss){
    for(int i=0;i<11;i++)
    if(ss==s[i]) return v[i];
    return -1;
}
int main(){
    //freopen("A.in.cpp","r",stdin);
    int n;
    while(scanf("%d",&n)+1){
        double ans=0.0;
        int tot=0;
        for(int i=0;i<n;i++){
            int k;
            string ss;
            scanf("%d",&k);
            cin>>ss;
            int val=doit(ss);
            if(val<-0.5) continue;
            ans+=val*k;
            tot+=k;
        }
        if(tot==0) puts("0.00");
        else printf("%.2f\n",ans/tot);
    }
    return 0;
}
