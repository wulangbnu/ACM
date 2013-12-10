#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll a[20];
int b[20];
void init()
{
    a[0]=1ll;
    for(int i=1;i<20;i++)
    a[i]=a[i-1]*i;
}
bool doit(ll x)
{
    int cnt=0;
    for(int i=19;i>=0;i--){
        if(x>=a[i]) x-=a[i],b[cnt++]=i;
    }
    if(x==0){
        for(int i=cnt-1;i>=0;i--)
        printf("%d!%c",b[i],i==0?'\n':'+');
    }
    return x==0;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    init();
    int T,cas=1;
    ll x;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        cin>>x;
        if(!doit(x)) puts("impossible");
    }
    return 0;
}
