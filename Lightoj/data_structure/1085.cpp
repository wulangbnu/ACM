#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#define MOD 1000000007
int a[N];
int b[N],c[N];
inline int lowbit(int i)
{
    return i&(-i);
}
void add(int x,int val)
{
    val%=MOD;
    for(int i=x;i<N;i+=lowbit(i)){
        a[i]+=val;
        a[i]%=MOD;
    }
}
int sum(int x)
{
    long long res=0;
    for(int i=x;i>0;i-=lowbit(i))
    res+=a[i];
    res%=MOD;
    return (int)res;
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,n,m,i,j,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            c[i-1]=b[i];
        }
        sort(c,c+n);
        int cnt=unique(c,c+n)-c;
        for(i=1;i<=n;i++){
             j=lower_bound(c,c+cnt,b[i])-c+1;
            add(j,sum(j-1)+1);
        }
        printf("%d\n",sum(N-1));
    }
    return 0;
}
