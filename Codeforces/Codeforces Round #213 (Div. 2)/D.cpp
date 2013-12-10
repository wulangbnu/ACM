#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=50+10;
const int M=10000+10;
int a[N],n,m;
bool dp[N*M];
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)==2){
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        memset(dp,false,sizeof(dp));
        dp[0]=true;

        for(int i=1;i<=n;i++)
        for(int j=sum;j>=a[i];j--){
            dp[j]|=dp[j-a[i]];
        }

        vector<int> vs;
        for(int i=0;i<=sum;i++) if(dp[i]) vs.push_back(i);

        int day=0,tot=0,cnt=vs.size();
        while(1){
            int x=upper_bound(vs.begin(),vs.end(),tot+m)-vs.begin();
            x=vs[--x];
            //printf("%d %d %d\n",tot,tot+m,x);
            if(x<=tot) break;
            tot=x;
            day++;
        }
        printf("%d %d\n",tot,day);
    }
    return 0;
}
