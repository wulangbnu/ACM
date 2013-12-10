#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100000+5;
int a[N];
int inline lowbit(int i)
{
    return i&(-i);
}
void add(int x,int val)
{
    for(int i=x;i<N;i+=lowbit(i))
    a[i]+=val;
}
int sum(int x)
{
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ret+=a[i];
    }
    return ret;
}
int p[N];
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++){
            scanf("%d",&p[i]);
            add(i,1);
        }
        int x,y,mid;
        for(i=n;i>=1;i--){
            x=1,y=n+1;
            while(x<y){
                mid=(x+y)/2;
                if(sum(mid)>=p[i]+1) y=mid;
                else x=mid+1;
            }
            add(x,-1);
        }
        printf("%d\n",n+1-x);
    }
    return 0;
}
