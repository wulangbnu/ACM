#include<cstdio>
int main()
{
    int T,cas=1,a,b,c;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d%d",&a,&b,&c);
        a*=a,b*=b,c*=c;
        if(a+b==c||a+c==b||b+c==a) puts("yes");
        else puts("no");
    }
    return 0;
}
