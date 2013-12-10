#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=150000+10;
int a[N],b[N];
int l[N],r[N],q[N];
inline int lowbit(int i)
{
    return i&(-i);
}
void ad(int x,int val)
{
    for(int i=x;i<N;i+=lowbit(i))
    a[i]+=val;
}
void add(int x,int y,int val)
{
    ad(x,val);
    ad(y+1,-val);
}
int sum(int x)
{
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
    ret+=a[i];
    return ret;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        memset(a,0,sizeof(a));
        int cnt=1;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d%d",&l[i],&r[i]);
            b[cnt++]=l[i];
            b[cnt++]=r[i];
        }
        for(i=0;i<m;i++){
            scanf("%d",&q[i]);
            b[cnt++]=q[i];
        }
        sort(b,b+cnt);
        cnt=unique(b,b+cnt)-b;
        for(i=0;i<n;i++){
            l[i]=lower_bound(b,b+cnt,l[i])-b+1;
            r[i]=lower_bound(b,b+cnt,r[i])-b+1;
            add(l[i],r[i],1);
        }
        for(i=0;i<m;i++){
            q[i]=lower_bound(b,b+cnt,q[i])-b+1;
            printf("%d\n",sum(q[i]));
        }

    }
    return 0;
}
