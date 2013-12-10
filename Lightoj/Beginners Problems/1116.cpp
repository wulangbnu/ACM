#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int T,cas=1;
    long long n,i;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        cin>>n;
        i=0;
        while(!(n&1)) n>>=1,i++;
        if(i==0) puts("Impossible");
        else cout<<n<<" "<<(1ll<<i)<<endl;
    }
    return 0;
}
