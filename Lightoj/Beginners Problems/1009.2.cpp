#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        if(n>m) swap(n,m);
        if(n==1) ans=m;
        else if(n==2){
            if(m&1) ans=m+1;
            else if((m/2)&1) ans=m+2;
        }
        else ans=(n*m+1)/2;
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
