#include<cstdio>
int main()
{
    int T,cas=1,n,ans,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=0;
        while(n--){
            scanf("%d",&i);
            ans+=i*(i>0);
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
