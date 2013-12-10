#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=60000+10;
const int M=60000+10;
int u[M],v[M],first[N],next[M],e;
int val[N];
int rmq[N][20],depth[N],pos[N],tot,fa[N];
void init()
{
    memset(first,-1,sizeof(first));
    tot=0;
    e=0;
}
void insert(int f,int t)
{
    u[e]=f; v[e]=t;
    next[e]=first[u[e]]; first[u[e]]=e++;
}
void dfs(int x,int deep,int father)
{
    fa[x]=father;
    depth[x]=deep;
    pos[x]=tot;
    rmq[tot++][0]=x;
    for(int i=first[x];i+1;i=next[i]){
        if(v[i]==father) continue;
        dfs(v[i],deep+1,x);
        rmq[tot++][0]=x;
    }
}
void RMQ()
{
    for(int j=1;(1<<j)<=tot;j++)
    for(int i=0;i+(1<<j)-1<tot;i++){
        int x=rmq[i][j-1],y=rmq[i+(1<<(j-1))][j-1];
        rmq[i][j]=depth[x]<depth[y]?x:y;
    }
}
int query(int i,int j)
{
    int x=pos[i],y=pos[j];
    if(x>y) swap(x,y);
    int k=log(y-x+1.0)/log(2.0)+1e-8;
    x=rmq[x][k];
    y=rmq[y-(1<<k)+1][k];
    int ff=depth[x]<depth[y]?x:y;
    int ans=val[ff];
    while(i!=ff){
        ans+=val[i];
        i=fa[i];
    }
    while(j!=ff){
        ans+=val[j];
        j=fa[j];
    }
    return ans;
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&val[i]);
        for(k=1;k<n;k++){
            scanf("%d%d",&i,&j);
            insert(i,j);
            insert(j,i);
        }
        dfs(0,0,-1);
        RMQ();
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&k,&i,&j);
            if(k==0) printf("%d\n",query(i,j));
            else val[i]=j;
        }
    }
    return 0;
}
