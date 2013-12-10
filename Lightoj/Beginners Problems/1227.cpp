#include<cstdio>
int main()
{
    int T,cas=1,n,p,q,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&p,&q);
        int sum=0,ans=0;
        for(i=1;i<=n;i++){
            scanf("%d",&j);
            sum+=j;
            if(i<=p&&sum<=q) ans=i;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
