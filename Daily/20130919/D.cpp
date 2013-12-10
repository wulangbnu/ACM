#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=700*2;
const int M=N*N*2;
const int INF=0x3f3f3f3f;
int u[M],v[M],cap[M],flow[M],first[N],next[M],e;
int dist[N],q[N],work[N],s,t;
void init(){
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,int val,int type=1){
    if(val<0) return;
    u[e]=f; v[e]=t; cap[e]=val; flow[e]=0;
    next[e]=first[f]; first[f]=e++;
    if(type) insert(t,f,0,0);
}
bool bfs(){
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    int l=0,r=0;
    q[r++]=s;
    while(l!=r){
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
int dfs(int x,int val){
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
int dinic(int n){
    int ret=0,tmp;
    while(bfs()){
        for(int i=0;i<=n;i++) work[i]=first[i];
        while((tmp=dfs(s,INF))>0) ret+=tmp;
    }
    return ret;
}
int n,m,d;
int a[30][30];
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d",&m,&n,&d)&&n+m+d){
        init();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]);

        int Max=n*m;
        s=0;
        t=n*m+Max+1;
        for(int i=1;i<=Max;i++) insert(s,i,Max);

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int x=i*m+j+1;
            for(int r=0;r<n;r++)
            for(int c=0;c<m;c++){
                int y=r*m+c+1+Max;
                if(abs(i-r)+abs(j-c)==0||abs(i-r)+abs(j-c)==d)
                    insert(x,y,Max);
            }
        }

        int tot=0;
        if(Max&1){
             for(int i=0;i<n;i++)
             for(int j=0;j<m;j++){
                int x=i*m+j+1+Max;
                if(a[i][j]==1) insert(x,t,Max),tot+=Max;
                else insert(x,t,Max-1), tot+=Max-1;
             }
        }else{
             for(int i=0;i<n;i++)
             for(int j=0;j<m;j++){
                int x=i*m+j+1+Max;
                if(a[i][j]==1) insert(x,t,Max-1), tot+=Max-1;
                else insert(x,t,Max) ,tot+=Max;
             }
        }

        if(dinic(t)==tot) puts("1");
        else puts("0");
    }
    return 0;
}
