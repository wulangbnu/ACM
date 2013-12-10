#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 150005
int a[N],b[N];
int inline lowbit(int i)
{
    return (i&(-i));
}
void add(int x,int val)
{
    for(int i=x;i<N;i+=lowbit(i))
    a[i]+=val;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
    res+=a[i];
    return res;
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,n,m,i,j,k,cas=1;
    char str[5];
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            add(i,1);
        }
        int tail=n;
        while(m--){
            scanf("%s%d",str,&k);
            if(str[0]=='c'){
                if(k>n) puts("none");
                else {
                    int x=1,y=tail;
                    while(x<y){
                        int mid=(x+y)/2;
                        if(sum(mid)>=k) y=mid;
                        else x=mid+1;
                    }
                    printf("%d\n",b[x]);
                    add(x,-1);
                    n--;
                }
            }
            else {
                b[tail]=k;
                add(tail,1);
                tail++;
                n++;
            }
        }

    }
    return 0;
}
