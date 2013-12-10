#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100000+5
int a[N];
char str[N];
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
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
    res+=a[i];
    return res;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d:\n",cas++);
        memset(a,0,sizeof(a));
        scanf("%s",str);
        for(i=0;str[i];i++){
            if(str[i]=='1') add(i+1,i+1,1);
        }
        scanf("%d",&m);
        while(m--){
            scanf("%s",str);
            if(str[0]=='I'){
                scanf("%d%d",&i,&j);
                add(i,j,1);
            }
            else{
                scanf("%d",&i);
                printf("%d\n",sum(i)%2);
            }
        }
    }
    return 0;
}
