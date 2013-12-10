#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 60000+10
int u[N],v[N],w[N],first[N],next[N];
int e;
int ans,tag;
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val)
{
    u[e]=f; v[e]=t; w[e]=val;
    next[e]=first[u[e]];
    first[u[e]]=e++;
}
void dfs(int x,int fa,int cur)
{
    if(cur>ans){
        ans=cur;
        tag=x;
    }
    for(int i=first[x];i+1;i=next[i]){
        if(v[i]==fa) continue;
        dfs(v[i],x,cur+w[i]);
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);


    int T,n,i,j,k,r,cas=1;
    scanf("%d",&T);
    while(T--){
        init();
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d%d%d",&j,&k,&r);
            insert(j,k,r);
            insert(k,j,r);
        }
        ans=0;
        dfs(0,-1,0);
        ans=0;
        dfs(tag,-1,0);
        printf("%d\n",ans);
    }
    return 0;
}
