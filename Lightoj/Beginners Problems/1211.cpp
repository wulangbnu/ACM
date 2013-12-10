#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,x1,y1,z1,x2,y2,z2,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        x1=y1=z1=1; x2=y2=z2=1000;
        scanf("%d",&n);
        while(n--){
            scanf("%d%d%d",&i,&j,&k);
            x1=max(i,x1),y1=max(j,y1),z1=max(k,z1);
            scanf("%d%d%d",&i,&j,&k);
            x2=min(i,x2),y2=min(j,y2),z2=min(k,z2);
        }
        if(x1>=x2||y1>=y2||z1>=z2){
            puts("0");continue;
        }
        printf("%d\n",(x2-x1)*(y2-y1)*(z2-z1));
    }
    return 0;
}
