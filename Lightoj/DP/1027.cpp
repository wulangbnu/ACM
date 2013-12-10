#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){

    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k,p,q;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        p=q=0;
        while(n--){
            scanf("%d",&i);
            p+=abs(i);
            if(i>0) q++;
        }
        if(q==0) puts("inf");
        else{
            i=__gcd(p,q);
            printf("%d/%d\n",p/i,q/i);
        }
    }
    return 0;
}
