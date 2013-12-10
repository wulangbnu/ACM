#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    ll n;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        cin>>n;
        ll x=sqrt(n-1)+1+(1e-8);
        n-=(x-1)*(x-1);
        ll i,j;
        if(x&1){
            i=0,j=x;
            if(n<=x) i+=n;
            else i+=x,j-=n-x;
        }
        else{
            i=x,j=0;
            if(n<=x) j+=n;
            else j+=x,i-=n-x;
        }
        cout<<j<<" "<<i<<endl;
    }
    return 0;
}
