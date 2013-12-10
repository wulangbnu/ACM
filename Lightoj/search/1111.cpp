#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000+10
#define M 10000+10
int u[M],v[M],first[N],next[M];
int e,num[N],f[N];
bool get[N];
void init()
{
    memset(first,-1,sizeof(first));
    memset(num,0,sizeof(num));
    memset(f,0,sizeof(f));
    e=0;
}
void insert(int f,int t)
{
    u[e]=f; v[e]=t;
    next[e]=first[u[e]];
    first[u[e]]=e++;
}
void dfs(int x,int val)
{
    if(get[x]) return;
    get[x]=true;
    f[x]+=val;
    for(int i=first[x];i+1;i=next[i])
    dfs(v[i],val);
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        init();
        printf("Case %d: ",cas++);
        scanf("%d%d%d",&k,&n,&m);
        int cnt=k;
        while(k--){
            scanf("%d",&i);
            num[i]++;
        }
        while(m--){
            scanf("%d%d",&i,&j);
            insert(i,j);
        }
        for(i=1;i<=n;i++){
            if(num[i]){
                memset(get,false,sizeof(get));
                 dfs(i,num[i]);
            }
        }
        int ans=0;
        for(i=1;i<=n;i++)
        if(f[i]==cnt){
           // printf("****** %d\n",i);
            ans++;
        }
        printf("%d\n",ans);

    }
    return 0;
}
