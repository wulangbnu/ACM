#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100000+10;
typedef long long ll;
ll d1[N],d2[N];
inline int lowbit(int i)
{
    return i&(-i);
}
void add(ll a[],int x,int val)
{
    for(int i=x;i<N;i+=lowbit(i))
    a[i]+=val;
}
ll sum(ll a[],int x)
{
    ll ret=0;
    for(int i=x;i>0;i-=lowbit(i))
    ret+=a[i];
    return ret;
}
void insert(int x,int y,int val)
{
    add(d1,x,val); add(d1,y+1,-val);
    add(d2,x,x*val); add(d2,y+1,-(y+1)*val);
}
ll query(int x,int y)
{
    return (y+1)*sum(d1,y)-x*sum(d1,x-1)-sum(d2,y)+sum(d2,x-1);
}
int main()
{
    #ifdef wulang
    freopen("in.cpp","r",stdin);
    #endif
    int T,n,m,i,j,k,r,cas=1;
    scanf("%d",&T);
    while(T--){
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        printf("Case %d:\n",cas++);
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d%d",&i,&j,&k);
            j++; k++;
            if(i==0){
                scanf("%d",&r);
                insert(j,k,r);
            }
            else {
                printf("%lld\n",query(j,k));
                //cout<<query(j,k)<<endl;
            }
        }

    }
    return 0;

}
