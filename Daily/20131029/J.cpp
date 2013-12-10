#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=35;
const int maxm=10005;

int n,m;
struct P {
    int v,t,id;
    bool operator<(const P&a)const {
        return t<a.t;
    }
} p[maxn];
bool vis[maxm];
int f[maxn][maxn][maxm];
int pnt[maxn][maxn][maxm][2];
int ret,idx;

int ti[maxn];
bool init(int ans) {
    int cnt=ans;
    for(int i=maxm-1; i>=0; i--)
        if(vis[i]) {
            ti[ans--]=i;
            if(ans==0)break;
        }
    if(ans)return 0;
}

void solve(int ans) {
    if(!init(ans))return;
    memset(f,-1,sizeof(f));
    f[0][0][0]=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=ans; j++)
            for(int k=0; k<maxm; k++) {
                if(f[i][j][k]==-1)continue;

                // printf("***\n");

                if(f[i+1][j][k]<f[i][j][k]) {
                    f[i+1][j][k]=f[i][j][k];
                    pnt[i+1][j][k][0]=j;
                    pnt[i+1][j][k][1]=k;
                }
                if(ti[j+1]-k>=p[i+1].t) {
                    if(f[i+1][j+1][k+p[i+1].t+1]<f[i][j][k]+p[i+1].v) {
                        f[i+1][j+1][k+p[i+1].t+1]=f[i][j][k]+p[i+1].v;
                        pnt[i+1][j+1][k+p[i+1].t+1][0]=j;
                        pnt[i+1][j+1][k+p[i+1].t+1][1]=k;
                    }
                }
            }
    int rett=-1;
    for(int i=0; i<maxm; i++)rett=max(rett,f[n][ans][i]);
    if(ret<rett) {
        ret=rett;
        idx=ans;
    }
    //printf("** %d :%d\n",ans,ret);
}

vector<int>path;
void dfs(int x,int y,int z) {
    if(x==0) return;
    if(f[x-1][y][z]==f[x][y][z]) dfs(x-1,y,z);
    else {
        path.push_back(p[x].id);
        dfs(x-1,y-1,z-p[x].t-1);
    }
}
void output() {
    printf("%d %d\n",ret,idx);
    int id=-1;
    for(int i=0; i<maxm; i++)
        if(f[n][idx][i]==ret) {
            // printf("** %d\n",i);
            id=i;
            break;
        }
    int x=n,y=idx,z=id;
    dfs(x,y,z);

    int cnt=0;
    for(int i=path.size()-1; i>=0; i--) {
        printf("%d %d\n",path[i],ti[++cnt]);
    }
}

int main() {
    //freopen("in.cpp","r",stdin);
    ret=-1;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",&p[i].v,&p[i].t);
        p[i].id=i;
    }
    sort(p+1,p+n+1);
    for(int i=1; i<=m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=x; j<y; j++)
            vis[j]=1;
    }
    for(int i=1; i<=n; i++)
        solve(i);
    if(ret==-1)printf("0 0\n");
    else {
        solve(idx);
        output();
    }
    return 0;
}
