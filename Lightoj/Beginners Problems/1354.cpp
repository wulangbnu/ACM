#include<cstdio>
#include<cstring>
bool doit(int a,int x){
    int ret=0,i=1;
    while(x){
        if(x%10==1) ret+=i;
        i<<=1;
        x/=10;
    }
    return a==ret;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,a,b,c,d;
    int x,y,z,q;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%d.%d.%d.%d",&x,&y,&z,&q);
        if(doit(a,x)&&doit(b,y)&&doit(c,z)&&doit(d,q)) puts("Yes");
        else puts("No");
    }
    return 0;
}
