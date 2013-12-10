#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20000+10;
const int M=20010*4*2+100;
const int INF=0x3f3f3f3f;
int u[M],v[M],cap[M],flow[M],first[N],next[M],e;
int q[N],dist[N],work[N],s,t;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val)
{
    u[e]=f; v[e]=t; cap[e]=val; flow[e]=0;
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
            if(flow[i]<cap[i]&&dist[v[i]]==-1){
                dist[v[i]]=dist[x]+1;
                q[r++]=v[i];
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
    return 0;
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
char str[110][110];
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        init();
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%s",str[i]);
        s=2*n*m+1; t=2*n*m+2;
        int cnt=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++){
           int x=i*m+j;
           insert(x,x+n*m,1);
           if(i==0||i==n-1||j==0||j==m-1) insert(x+n*m,t,1);
           else{
              for(int k=0;k<4;k++){
                int xx=i+dx[k],yy=j+dy[k];
                if(str[xx][yy]=='*') continue;
                insert(x+n*m,xx*m+yy,1);
              }
           }
           if(str[i][j]=='*'){
                insert(s,x,1);
                cnt++;
           }
        }
        if(dinic(t)==cnt) puts("yes");
        else puts("no");
    }
    return 0;
}
