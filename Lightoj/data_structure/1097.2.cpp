#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1429431+1;
int a[N],p[N],b[N],cnt=1;
inline int lowbit(int i)
{
    return i&(-i);
}
void add(int x,int val)
{
    for(int i=x;i<cnt;i+=lowbit(i))
    a[i]+=val;
}
int sum(int x)
{
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
    ret+=a[i];
    return ret;
}
int find(int i)
{
    int x=1,y=cnt;
    while(x<y){
        int mid=(y-x)/2+x;
        if(sum(mid)>=i) y=mid;
        else x=mid+1;
    }
    return x;
}
void init()
{
    int i,j,n;
    for(i=1;i<N;i+=2) p[cnt++]=i;
    for(i=2;i<100;i++){
        n=cnt;
        cnt=p[i];
        for(j=p[i];j<n;j++){
            if(j%p[i]==0) continue;
            p[cnt++]=p[j];
        }
    }
    for(i=1;i<=cnt;i++) add(i,1);
    for(i=100;i<=100000;i++){
        p[i]=p[find(i)];
        for(j=p[i];j<cnt;j+=p[i]) b[j]=find(j);
        for(j=p[i];j<cnt;j+=p[i]) add(b[j],-1);
    }
}
int main()
{

    //freopen("in.cpp","r",stdin);
    init();
    int T,cas=1,n;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        printf("%d\n",p[n]);
    }
    return 0;
}
