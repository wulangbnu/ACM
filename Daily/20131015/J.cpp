#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=100;
int a[6];
int doit(int a,int b,int c,int x,int y){
    int cnt=(x>a)+(y>b);
    if(cnt==0) return INF;
    if(cnt==1) return c+1;
    if(cnt==2) return 1;
}
int main(){
    //freopen("J.in.cpp","r",stdin);
    while(1){
        for(int i=1;i<=5;i++) scanf("%d",&a[i]);
        if(a[1]==0) return 0;
        int ans=doit(a[1],a[2],a[3],a[4],a[5]);
        //printf("%d\n",ans);
        ans=max(ans,doit(a[1],a[3],a[2],a[4],a[5]));
        ans=max(ans,doit(a[2],a[1],a[3],a[4],a[5]));
        ans=max(ans,doit(a[2],a[3],a[1],a[4],a[5]));
        ans=max(ans,doit(a[3],a[1],a[2],a[4],a[5]));
        ans=max(ans,doit(a[3],a[2],a[1],a[4],a[5]));

        sort(a+1,a+5+1);
        for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++){
            if(ans==a[j]) ans++;
        }

        if(ans>52) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
