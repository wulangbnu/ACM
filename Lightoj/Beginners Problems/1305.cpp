#include<cstdio>
#include<algorithm>
using namespace std;
int T,cas=1,x1,y1,x2,y2,x3,y3;
int doit(){
    x1-=x2; y1-=y2;
    x3-=x2; y3-=y2;
    int ans=x1*y3-y1*x3;
    printf("%d\n",abs(ans));
}
int main(){
    //freopen("in.cpp","r",stdin);
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        printf("%d %d ",x3+x1-x2,y3+y1-y2);
        doit();
    }
    return 0;
}
