#include<cstdio>
#include<iostream>
using namespace std;
#define N 10000+5
#define mod 10000007
typedef long long ll;
ll f[N];
void init(int n)
{

    for(int i=6;i<=n;i++)
    f[i]=(f[i-1]+f[i-2]+f[i-3]+f[i-4]+f[i-5]+f[i-6])%mod;
}
int main()
{

    int T,n,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
       printf("Case %d: ",cas++);
       for(i=0;i<6;i++)
       {
          cin>>f[i];
          f[i]%=mod;
       }
       scanf("%d",&n);
       init(n);
       printf("%lld\n",f[n]);
    }
    return 0;
}
