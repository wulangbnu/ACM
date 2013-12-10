#include<cstdio>
#include<cstring>
char str[105][25];
int a[105];
int main(){
   // freopen("in.cpp","r",stdin);

    int T,cas=1,n,i,j,k,r;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        int mind=1<<30,maxd=-1,x,y;
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
            scanf("%d%d%d",&j,&k,&r);
            a[i]=j*k*r;
            if(a[i]<mind){
                mind=a[i];
                x=i;
            }
            if(a[i]>maxd){
                maxd=a[i];
                y=i;
            }
        }
        if(a[x]==a[y]) puts("no thief");
        else printf("%s took chocolate from %s\n",str[y],str[x]);
    }
    return 0;
}
