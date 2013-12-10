#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100000+5;
int a[N];
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
    if(x>y) return;
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
struct Point
{
    int x,y,id,ans;
    bool operator <(const Point tt) const{
        return y<tt.y;
    }
    void input(){
        scanf("%d%d",&x,&y);
    }
}p[N];
bool cmp(Point a,Point b)
{
    return a.id<b.id;
}
int pre[N],pos[N];
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        memset(a,0,sizeof(a));
        memset(pos,0,sizeof(pos));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            pre[i]=pos[k];
            pos[k]=i;
        }
        for(i=0;i<m;i++){
           p[i].input();
           p[i].id=i;
        }
        sort(p,p+m);
        k=0;
        for(i=1;i<=n;i++){
            add(pre[i]+1,i,1);
            while(k<m&&p[k].y==i){
                p[k].ans=sum(p[k].x);
                k++;
            }
        }
        sort(p,p+m,cmp);
        for(i=0;i<m;i++)
        printf("%d\n",p[i].ans);
    }
    return 0;
}
