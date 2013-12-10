#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn=18;
const int N=18;
const int INF=0x3f3f3f3f;

int n,m;
int d[maxn][maxn];
int f[1<<maxn][maxn],pnt[1<<maxn][maxn][2];
int dp[1<<maxn][2];

bool pd(int &ret,int val) {
    if(ret==-1||ret>val) {
        ret=val;
        return 1;
    }
    return 0;
}

int dis[N][N],fa[N][N];
vector<int> path[N][N];
queue<int> q;
bool inq[N];
void spfa(int s,int dis[],int fa[]) {
    for(int i=0; i<18; i++) dis[i]=INF;
    memset(inq,false,sizeof(inq));
    dis[s]=0;
    q.push(s);
    inq[s]=true;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        inq[x]=false;
        for(int y=0; y<18; y++) {
            if(d[x][y]==-1) continue;
            if(dis[x]+d[x][y]<dis[y]) {
                dis[y]=dis[x]+d[x][y];
                fa[y]=x;
                if(!inq[y]) {
                    q.push(y);
                    inq[y]=true;
                }
            }
        }
    }
}

void doit(int i,int j) {
    path[i][j].clear();
    for(int x=j,y=fa[i][x]; x!=i; x=y,y=fa[i][x]) {
        path[i][j].push_back(x);
    }
    path[i][j].push_back(i);
}
void floyd() {
    for(int i=0; i<n; i++) spfa(i,dis[i],fa[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            doit(i,j);
        }

    /*printf("** %d\n",path[0][3].size());
    for(int i=0;i<path[0][3].size();i++)
    printf("%d ",path[0][3][i]);
    printf("\n");*/

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                if(d[i][k]==-1||d[k][j]==-1)continue;
                pd(d[i][j],d[i][k]+d[k][j]);
            }
}

vector<int>ans1,ans2;

int main() {
    freopen("in.cpp","r",stdin);
    scanf("%d%d",&n,&m);
    memset(d,-1,sizeof(d));
    memset(f,-1,sizeof(f));
    f[1][0]=0;
    for(int i=0; i<m; i++) {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        x--,y--;
        pd(d[x][y],t),pd(d[y][x],t);
    }
    floyd();
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++)
            if(i&(1<<j)) {
                if(f[i][j]==-1)continue;
                // printf("**\n");
                for(int k=0; k<n; k++) {
                    if(i&(1<<k))continue;
                    if(d[j][k]==-1)continue;
                    // printf("**\n");
                    if(pd(f[i|(1<<k)][k],f[i][j]+d[j][k])) {
                        pnt[i|(1<<k)][k][0]=i;
                        pnt[i|(1<<k)][k][1]=j;
                    }
                }
            }
    //printf("** %d\n",f[(1<<n)-1][1]);
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++)
            if(f[i][j]!=-1&&pd(dp[i][0],f[i][j]))
                dp[i][1]=j;
    int ret=-1,x1,y1,x2,y2;
    for(int i=0; i<(1<<n); i++) {
        if(dp[i][0]==-1)continue;
        int tt=(((1<<n)-1)^i);
        tt|=1;
        /*for(int j=i;; j=((j-1)&i)) {
            if(dp[j|tt][0]!=-1&&pd(ret,max(dp[i][0],dp[j|tt][0]))) {
                x1=i,y1=dp[i][1];
                x2=(j|tt),y2=dp[x2][1];
            }
            if(!j)break;*/
        if(dp[tt][0]!=-1&&pd(ret,max(dp[i][0],dp[tt][0]))) {
            x1=i,y1=dp[i][1];
            x2=tt,y2=dp[tt][1];
        }
    }

    //printf("%d %d %d %d\n",x1,y1,x2,y2);

    printf("%d\n",ret);
    ans1.clear(),ans2.clear();
    int x=x1,y=y1;
    while(x!=1) {
        int px=pnt[x][y][0];
        int py=pnt[x][y][1];
        for(int i=0; i<path[py][y].size()-1; i++)
            ans1.push_back(path[py][y][i]+1);
        x=px,y=py;
    }
    ans1.push_back(1);
    x=x2,y=y2;
    while(x!=1) {
        int px=pnt[x][y][0];
        int py=pnt[x][y][1];
        for(int i=0; i<path[py][y].size()-1; i++)
            ans2.push_back(path[py][y][i]+1);
        x=px,y=py;
    }
    ans2.push_back(1);
    printf("%d",ans1.size());
    for(int i=ans1.size()-1; i>=0; i--)
        printf(" %d",ans1[i]);
    printf("\n");
    printf("%d",ans2.size());
    for(int i=ans2.size()-1; i>=0; i--)
        printf(" %d",ans2[i]);
    printf("\n");
    return 0;
}
