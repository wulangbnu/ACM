#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int T,cas=1,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&i,&j);
        printf("Case %d: %d\n",cas++,19+(abs(i-j)+i)*4);
    }
    return 0;
}
