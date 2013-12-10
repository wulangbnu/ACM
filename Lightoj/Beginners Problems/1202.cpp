#include<cstdio>
#include<algorithm>
using namespace std;
bool check(int a,int b)
{
    return  !((a+b)&1)&&!((a-b)&1);
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,x1,x2,y1,y2;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(abs(x1-x2)==abs(y1-y2)){
            puts("1");
            continue;
        }
        if(check(x1-x2,y1-y2)){
            puts("2");
            continue;
        }
        puts("impossible");
    }
    return 0;
}
