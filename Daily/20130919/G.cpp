#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<string>
using namespace std;
const int maxn=105;
const int maxm=1005;

int f[maxn][maxn][maxm];
int head[maxn],num,next[maxm],ev[maxm],ew[maxm];
int n,m,c;

void init() {
    num=0;
    memset(head,-1,sizeof(head));
    memset(f,-1,sizeof(f));
}

void add_edge(int u,int v,int w) {
    next[++num]=head[u];
    head[u]=num;
    ev[num]=v,ew[num]=w;
}

int main() {
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d",&n,&m,&c)) {
        if(n==0&&m==0&&c==0)break;
        init();
        for(int i=1; i<=m; i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
        }
        f[1][1][0]=0;
        for(int j=1; j<n; j++)
            for(int i=1; i<=n; i++)
                for(int k=0; k<=m; k++) {
                    if(f[i][j][k]==-1)continue;
                    for(int r=head[i]; r!=-1; r=next[r]) {
                        int v=ev[r],w=ew[r];
                        int tt=f[i][j][k]+w;
                        if(f[v][j+1][k]==-1)f[v][j+1][k]=tt;
                        else f[v][j+1][k]=min(f[v][j+1][k],tt);
                        tt=f[i][j][k];
                        if(f[v][j+1][k+1]==-1)f[v][j+1][k+1]=tt;
                        else f[v][j+1][k+1]=min(f[v][j+1][k+1],tt);
                    }
                }
        int ret=-1;
        for(int k=m; k>=0; k--)
            for(int j=1; j<=n; j++) {
                if(f[n][j][k]==-1)continue;
                if(f[n][j][k]>c)continue;
                ret=k;
            }
        printf("%d\n",ret);
    }
    return 0;
}
