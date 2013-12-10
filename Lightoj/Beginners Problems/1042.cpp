#include<cstdio>
int main()
{
    int T,cas=1,n,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;;i++) if((1<<i)&n) break;
        for(j=i+1;;j++) if(!((1<<j)&n)) break;
        for(i=j-1;;i--) if((1<<i)&n) break;
        n+=(1<<j)-(1<<i);
        for(j=0,i--;i>=0;i--) if((1<<i)&n) j++,n-=(1<<i);
        n+=(1<<j)-1;
        printf("Case %d: %d\n",cas++,n);
    }
    return 0;
}
