#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;
int a[N];
int main()
{

   // freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k;
    char str[5];
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        while(m--){
            scanf("%s",str);
            if(str[0]=='S'){
                scanf("%d",&k);
                for(i=0;i<n;i++) a[i]+=k;
            }
            else if(str[0]=='M'){
                scanf("%d",&k);
                for(i=0;i<n;i++) a[i]*=k;
            }
            else if(str[0]=='D'){
                scanf("%d",&k);
                for(i=0;i<n;i++) a[i]/=k;
            }
            else if(str[0]=='R'){
                for(i=0;i<n-1-i;i++)
                swap(a[i],a[n-1-i]);
            }
            else if(str[0]=='P'){
                scanf("%d%d",&i,&j);
                swap(a[i],a[j]);
            }
        }
        for(i=0;i<n;i++)
        printf("%d%c",a[i],i==n-1?'\n':' ');
    }
    return 0;
}
