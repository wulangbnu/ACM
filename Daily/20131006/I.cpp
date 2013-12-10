#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=300000+10;
const int INF=0x3f3f3f3f;
int s,n;
int a[N],pre[N],next[N],pos[N];
int cnt[N];
void doit(){

    memset(cnt,0,sizeof(cnt));
    int tot=1;
    for(int x=s+1;x+s-1<=n+2*s;x+=s,tot++){
        for(int y=x;y<=x+s-1;y++){
            if(pre[y]>=x) cnt[tot]++;
        }
    }

    int x=s+1,ans=0;
    for(int i=1;i<=s;i++){
        int k=1;
        for(int j=1;j<=tot;j++){
            if(cnt[j]>0){
                k=0;
                break;
            }
        }
        ans+=k;
        for(int k=1,j=x;j+s-1<=n+2*s;j+=s,k++){
            if(pre[j+s-1]>=j) cnt[k]--;
            if(next[j-1]<=j-1+s-1) cnt[k]++;
        }
        x--;
    }
    printf("%d\n",ans);
}
int main(){

    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&s,&n);
        for(int i=1;i<=s;i++) a[i]=s+i;
        for(int i=s+1;i<=n+s;i++) scanf("%d",&a[i]);
        for(int i=n+s+1,j=2*s+1;i<=n+2*s;i++,j++) a[i]=j;

        //for(int i=1;i<=n+2*s;i++) printf("%d ",a[i]); puts("");

        for(int i=1;i<=3*s;i++) pos[i]=-INF;
        for(int i=1;i<=n+2*s;i++){
            pre[i]=pos[a[i]];
            pos[a[i]]=i;
        }
        for(int i=1;i<=3*s;i++) pos[i]=INF;
        for(int i=n+2*s;i>=1;i--){
            next[i]=pos[a[i]];
            pos[a[i]]=i;
        }
        doit();
    }
    return 0;
}
