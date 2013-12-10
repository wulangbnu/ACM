#include<cstdio>
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    long long n,m;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",m*n/2);
    }
    return 0;
}
