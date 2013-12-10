#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int doit(long long x)
{
    return x/3+(x+1)/3;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&i,&j);
        printf("%d\n",doit(j)-doit(i-1));
    }
    return 0;
}
