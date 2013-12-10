#include<cstdio>
int main()
{
    int T,cas=1,n,x1,y1,x2,y2,x,y;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
        while(n--){
            scanf("%d%d",&x,&y);
            if(x>x1&&x<x2&&y>y1&&y<y2) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
