#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=5005;

int m,n,s,k;
char str[maxn];

int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d%d",&n,&m,&s,&k)+1){
        scanf("%s",str);

        int cnt=0;
        for(int i=0;i<m;i++)
        if(str[i]=='*') cnt++;

        int ss=m;
        for(int i=0;i<m;i++)
        if(str[i]=='*'){
            ss=i; break;
        }
        int cnt2=(ss!=m);
        for(int i=ss+1;i<m;i++){
            if(str[i-1]=='*'&&str[i]=='*') cnt2++;
        }

        //printf("!! %d %d\n",cnt,cnt2);
        if(cnt2!=cnt||(cnt!=s&&cnt!=0)){
            puts("Impossible");
            continue;
        }

        if(cnt!=0){
            if(max(k-n+s,1)!=min(s,k)) puts("Ambiguous");
            else puts("Unique");
        }else{
            int ans=0;
            ans+=max(0,k-1-s+1)*(m-s+1);
            ans+=max(0,n-k-s+1)*(m-s+1);
            if(ans==0) puts("Impossible");
            else if(ans==1) puts("Unique");
            else puts("Ambiguous");
        }
    }
    return 0;
}
