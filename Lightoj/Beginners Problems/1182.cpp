#include<cstdio>
int main()
{
    int T,cas=1,x;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&x);
        int ans=0;
        for(x;x;x&=x-1) ans++;
        printf("Case %d: %s\n",cas++,(ans&1)?"odd":"even");
    }
    return 0;
}
