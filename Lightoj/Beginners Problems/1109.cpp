#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000+5;
int b[N],a[N];
bool cmp(int i,int j)
{
    if(b[i]!=b[j]) return b[i]<b[j];
    return i>j;
}
void init()
{
    for(int i=1;i<=1000;i++){
        a[i]=i;
        for(int j=i;j<=1000;j+=i)
        b[j]++;
    }
    sort(a+1,a+1+1000,cmp);
}
int main()
{
    //freopen("in.cpp","r",stdin);
    init();
    int T,cas=1,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case %d: %d\n",cas++,a[n]);
    }
    return 0;
}
