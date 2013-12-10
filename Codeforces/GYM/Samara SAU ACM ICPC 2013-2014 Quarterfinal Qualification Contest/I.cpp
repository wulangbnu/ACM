#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int N=200000+10;
int n,a[N],b[N];
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);

        int ans=0,harm=0;
        priority_queue<int> q;
        for(int i=1;i<=n;i++){
            if(b[i]>a[i]){ ans++; continue;}
            q.push(b[i]);
            harm+=b[i];
            while(harm>a[i]){
                harm-=q.top();
                q.pop();
                ans++;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
