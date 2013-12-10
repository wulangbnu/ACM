#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N=4000+10;
const int M=N*85;
int get[M];
int sum[N];
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    int n,m;
    while(scanf("%d",&m)==1){
        string ss;
        cin>>ss;
        n=ss.size();
        for(int i=0;i<n;i++) sum[i+1]=sum[i]+ss[i]-'0';
        //for(int i=1;i<=n;i++) cout<<sum[i]<<" "; cout<<endl;
        memset(get,0,sizeof(get));
        for(int i=0;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        get[sum[j]-sum[i]]++;
        ll ans=0;
        for(int i=0;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            int x=sum[j]-sum[i];
            if(x==0){
                if(m==0) ans+=n*(n+1)/2;
            }else{
                if(m%x) continue;
                if(m/x<M) ans+=get[m/x];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
