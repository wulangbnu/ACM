#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N=200000+10;
using namespace std;
typedef long double db;
db P[N],Q[N];
int n;
void init(db p){
    P[0]=Q[0]=1.0;
    for(int i=1;i<=n;i++){
        P[i]=P[i-1]*p;
        Q[i]=Q[i-1]*(1.0-p);
    }
}
db  doit(int n,db pn,db q){
    db ans=0.0;
    db x=1.0, y=1.0;
    for(int m=0;m<=n;m++){
        ans+=x*(n-m)*pn*y;
        x*=(n+m+1.0)/(m+1.0);
        y*=q;
    }
    //cout<<ans<<endl;
    return (1.0-q)*ans;
}
int main(){
    freopen("in.cpp","r",stdin);
    double p;
    int cas=0;
    while(scanf("%d%lf",&n,&p)+1){
        init(p);
        double ans=doit(n,P[n],1-p)+doit(n,Q[n],p);
        printf("Case %d: %.6f\n",++cas,ans);
    }
    return 0;
}
