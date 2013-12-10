#include<cstdio>
char str[105];
int main(){

    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        scanf("%d",&n);
        k=0;
        while(n--){
            scanf("%s",str);
            if(str[0]=='d'){
                scanf("%d",&i);
                k+=i;
            }
            else printf("%d\n",k);
        }
    }
    return 0;
}
