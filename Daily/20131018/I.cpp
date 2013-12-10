#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=100;
const int maxm=10005;

int n,m,vis[maxn];
bool f[maxn][10][maxm];
int pnt[maxn][10][maxm][2];
int A[maxn];

void init() {
    A[0]=1%n;
    for(int i=1; i<maxn; i++)
        A[i]=A[i-1]*10%n;
}

void dp() {
    for(int i=0; i<maxn-1; i++)
        for(int j=0; j<10; j++)
            for(int k=0; k<n; k++) {
                if(!f[i][j][k])continue;
                if(j>0&&k==0)return;
                for(int r=0; r<10; r++) {
                    if(vis[r])continue;
                    int tt=(A[i]*r+k)%n;
                    if(f[i+1][r][tt]) {
                        if(pnt[i+1][r][tt][0]>j) {
                            pnt[i+1][r][tt][0]=j;
                            pnt[i+1][r][tt][1]=k;
                        }
                    } else {
                        f[i+1][r][tt]=1;
                        pnt[i+1][r][tt][0]=j;
                        pnt[i+1][r][tt][1]=k;
                    }
                }
            }
}

void solve(int ncase) {
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    dp();
    int x=-1,y=-1;
    for(int i=maxn-1; i>=1; i--)
        for(int j=9; j>=1; j--)
            if(f[i][j][0]) {
                x=i,y=j;
            }
    if(x==-1)printf("Case %d: %d\n",ncase,-1);
    else {
        printf("Case %d: ",ncase);
        int z=0;
        while(x) {
            printf("%d",y);
            int py=pnt[x][y][z][0];
            int pz=pnt[x][y][z][1];
            x--,y=py,z=pz;
        }
        printf("\n");
    }
}

int main() {
    //freopen("in.cpp","r",stdin);
    int ncase=0;
    while(~scanf("%d%d",&n,&m)) {
        init();
        memset(vis,0,sizeof(vis));
        for(int i=0; i<m; i++) {
            int x;
            scanf("%d",&x);
            vis[x]=1;
        }
        solve(++ncase);
    }
    return 0;
}
