#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
int n,s,w,q;
int a[N],b[N],p[N];
int qq[N];
void init(){
    int g = s;
    for(int i=0; i<n; i++) {
          a[i] = (g/7) % 10;
          if( g%2 == 0 ) { g = (g/2); }
          else           { g = (g/2) ^ w; }
    }
    p[0]=1;
    for(int i=1;i<=n;i++) p[i]=10*p[i-1]%q;
}
void doit(){
    p[0]=0;
    for(int i=1;i<n;i++) p[i]=p[i-1]+(a[i-1]!=0);
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]%q==0){
            ans+=p[i];
            if(a[i]!=0) ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d%d",&n,&s,&w,&q)&&(n+s+w+q)){
        init();
        if(q==2||q==5){
            doit();
            continue;
        }
        for(int k=0,i=n-1;i>=0;i--){
            k=(a[i]*p[n-1-i]+k)%q;
            b[i]=k;
        }

        for(int i=0;i<n;i++) qq[i]=b[i];
        qq[n]=0;
        sort(qq,qq+n+1);
        int cnt=unique(qq,qq+n+1)-qq;

        for(int i=0;i<n;i++)
        b[i]=lower_bound(qq,qq+cnt,b[i])-qq;

        memset(p,0,sizeof(p));
        for(int i=0;i<n;i++)
        if(a[i]>0) p[b[i]]++;

        int ans=0;
        for(int k=0,i=n-1;i>=0;i--){
            ans+=p[k];
            k=b[i];
            if(a[i]>0) p[k]--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
