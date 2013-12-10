#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200+10;
const int M=210*210*2+100;
const int INF=0x3f3f3f3f;
int u[M],v[M],cap[M],flow[M],first[N],next[M],e;
int q[N],work[N],dist[N],s,t;
int low_in[N],low_out[N],low_flow[M];
void init()
{
    memset(first,-1,sizeof(first));
    memset(low_in,0,sizeof(low_in));
    memset(low_out,0,sizeof(low_out));
    e=0;
}
void insert(int f,int t,int low_val,int up_val)
{
    low_out[f]+=low_val; low_in[t]+=low_val; low_flow[e]=low_val;
    u[e]=f; v[e]=t; cap[e]=up_val-low_val; flow[e]=0;
    next[e]=first[u[e]]; first[u[e]]=e++;
    u[e]=t; v[e]=f; cap[e]=0; flow[e]=0;
    next[e]=first[u[e]]; first[u[e]]=e++;
}
bool bfs()
{
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    int l=0,r=0;
    q[r++]=s;
    while(l<r){
        int x=q[l++];
        for(int i=first[x];i+1;i=next[i]){
            int y=v[i];
            if(flow[i]<cap[i]&&dist[y]==-1){
                dist[y]=dist[x]+1;
                q[r++]=y;
            }
        }
    }
    return dist[t]!=-1;
}
int dfs(int x,int val)
{
    if(x==t) return val;
    for(int &i=work[x];i+1;i=next[i]){
        int y=v[i],tmp;
        if(flow[i]<cap[i]&&dist[y]==dist[x]+1&&(tmp=dfs(y,min(val,cap[i]-flow[i])))>0){
            flow[i]+=tmp;
            flow[i^1]-=tmp;
            return tmp;
        }
    }
    return  0;
}
int dinic(int n)
{
    int ans=0;
    while(bfs()){
        for(int i=0;i<=n;i++) work[i]=first[i];
        while(1){
            int tmp=dfs(s,INF);
            if(tmp==0) break;
            ans+=tmp;
        }
    }
    return ans;
}
int min_flow(int n)
{
    int tmp_s=s, tmp_t=t,tot=0;
    s=n+1; t=n+2;
    for(int i=0;i<=n;i++){
        if(low_in[i]>0){
            insert(s,i,0,low_in[i]);
            tot+=low_in[i];
        }
        if(low_out[i]>0){
            insert(i,t,0,low_out[i]);
        }
    }
    insert(tmp_t,tmp_s,0,INF);
    dinic(n+2);
    return 0;
}
int ans[N][N];
void doit(int n,int m)
{
    for(int x=1;x<=n+m-1;x++){
        for(int i=first[x];i+1;i=next[i]){
            if(v[i]==0)  continue;
            int a=x+1, b=v[i]-(n+m)-m;
            ans[(a+b)/2][(a-b)/2]=flow[i]+low_flow[i];
        }
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        init();
        printf("Case %d:\n",cas++);
        scanf("%d%d",&n,&m);
        s=0; t=2*(n+m)+1;
        for(i=1;i<=n+m-1;i++){
            scanf("%d",&j);
            insert(s,i,j,j);
        }
        for(i=1;i<=n+m-1;i++){
            scanf("%d",&j);
            insert(i+n+m,t,j,j);
        }
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            int x=i+j-1,y=i-j+m;
            insert(x,y+n+m,1,100);
        }
        min_flow(t);
        doit(n,m);
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        printf("%d%c",ans[i][j],j==m?'\n':' ');
    }
    return 0;
}
