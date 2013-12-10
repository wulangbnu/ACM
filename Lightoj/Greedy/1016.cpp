#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50000+5;
int a[N];
int main()
{

    //freopen("in.cpp","r",stdin);
    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d%d",&j,&a[i]);
        }
        sort(a,a+n);
        int ans=0;
        for(i=0;i<n;){
            ans++;
            for(j=i+1;j<n&&a[j]<=a[i]+m;j++);
            i=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
