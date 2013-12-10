#include<cstdio>
int main(){
    //freopen("in.cpp","r",stdin);
    int T,n,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        int ans=0;
        i=2;
        for(k=1;k<=n;k++){
            scanf("%d",&j);
            ans+=(j-i+4)/5;
            i=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
