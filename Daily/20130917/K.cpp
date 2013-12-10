#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000000+10;
char str[2][N];
int cnt[2][10];
int ans[N];
void doit(char s[],int a[]){
    for(int i=0;i<10;i++) a[i]=0;
    for(int i=0;s[i];i++) a[s[i]-'0']++;
}
int work(int x,int type=-1){
    int ret=0;
    for(int i=0;i<10;i++){
        int j=(x-i+10)%10;
        if(i==type||j==type) continue;
        int k=min(cnt[0][i],cnt[1][j]);
        if(type==0&&k>0){
            cnt[0][i]-=1;
            cnt[1][j]-=1;
            return 1;
        }
        ret+=k;
        cnt[0][i]-=k;
        cnt[1][j]-=k;
    }
    return ret;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",cas++);
        scanf("%s%s",str[0],str[1]);
        doit(str[0],cnt[0]);
        doit(str[1],cnt[1]);
        int i,tot=0;
        for(i=9;i>=0;i--)
        if(work(i,0)){
            ans[tot++]=i;
            break;
        }
        for(i=9;i>=0;i--){
            int k=work(i);
            while(k--) ans[tot++]=i;
        }

        int flag=0;
        for(i=0;i<tot;i++){
            if(ans[i]>0){
                printf("%d",ans[i]);
                flag=1;
            }
            if(ans[i]==0&&flag) printf("%d",ans[i]);
        }
        if(flag==0) puts("0");
        else puts("");
    }
    return 0;
}
