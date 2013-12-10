#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100000+10;
int a[N],b[N],pre[N];
int n,m,k,ans;
void doit(int s,int id){
    //printf("!! %d %d %d\n",s,id,ans);
    if(s>n) return;
    if(id==m){
        ans+=n-s+1;
        return;
    }
    int num=b[id+1]-b[id]-1;
    if(num>=n-s+1){
        ans+=n-s+1;
        return;
    }
    ans+=num+1;
    s+=num-1;
    s=pre[s];
    doit(s,id+1);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d",&n,&m,&k)+1){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        int j=n,sum=a[n];
        for(int i=n;i>=1;i--){
            while(sum<=k&&j>1){
                j--;
                sum+=a[j];
            }
            pre[i]=j;
            sum-=a[i];
            //printf("~~ %d %d\n",i,pre[i]);
        }
        ans=0;
        pre[0]=1;
        doit(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
