#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXN 100010
#define eps 1e-8
int N,M;
int u[MAXN],v[MAXN],first[MAXN],nexte[MAXN],w[MAXN],e;
int f[MAXN][2],far[MAXN],tag[MAXN],ans[MAXN],mark[MAXN][2];
int depth[MAXN],pos[MAXN],father[MAXN][20],tot;

int chmin[MAXN][20],chmax[MAXN][20];

int LOG[MAXN];
void prep(){
    LOG[0]=-1;
    for(int i=1;i<MAXN;i++) LOG[i]=LOG[i>>1]+1;
}
void init() {
    memset(first,-1,sizeof(first));
    memset(f,0,sizeof(f));
    e=tot=0;
}
void insert(int f,int t,int val) {
    u[e]=f;
    v[e]=t;
    nexte[e]=first[u[e]];
    w[e]=val;
    first[u[e]]=e++;
}
void dfs(int x,int fa) {
    pos[x] = tot;
    depth[x]=depth[fa]+1;
    father[x][0]=fa;
    int flag = 1;
    for(int i=first[x]; i+1; i=nexte[i]) {
        if(v[i]==fa) continue;
        dfs(v[i],x);
        flag=0;
        if(f[v[i]][0]+w[i]>f[x][0]) {
            f[x][1]=f[x][0];
            f[x][0]=f[v[i]][0]+w[i];
            tag[x]=v[i];
            mark[x][1]=mark[x][0];
            mark[x][0]=mark[v[i]][0];
        } else if(f[v[i]][0]+w[i]>f[x][1]) {
            f[x][1]=f[v[i]][0]+w[i];
            mark[x][1]=mark[v[i]][0];
        }
    }
    if(flag) {
        mark[x][0]=x;
    }
}
void dfs(int x,int fa,int val,int ff) {
    if(f[x][0]>val) {
        ans[x]=f[x][0];
        far[x]=mark[x][0];
    } else {
        ans[x]=val;
        far[x]=ff;
    }
    for(int i=first[x]; i+1; i=nexte[i]) {
        if(v[i]==fa) continue;
        if(tag[x]!=v[i]) {
            if(f[x][0]>val)
                dfs(v[i],x,f[x][0]+w[i],mark[x][0]);
            else dfs(v[i],x,val+w[i],ff);
        } else {
            if(f[x][1]>val)
                dfs(v[i],x,f[x][1]+w[i],mark[x][1]);
            else dfs(v[i],x,val+w[i],ff);
        }
    }
}
void rmq() {
    for(int i = 1; i <= N; i++)  chmin[i][0] = chmax[i][0] = ans[i];
    for(int j = 1; (1 << j) <= N; j++) {
        for(int i = 1; i + (1 << j) - 1 <= N; i++) {
            chmin[i][j] = min(chmin[i][j - 1], chmin[i + (1 << (j - 1))][j - 1]);
            chmax[i][j] = max(chmax[i][j - 1], chmax[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int x, int y) {
    int i = LOG[y - x + 1];
    int p = min(chmin[x][i], chmin[y - (1 << i) + 1][i]);
    int q = max(chmax[x][i], chmax[y - (1 << i) + 1][i]);
    return q - p;
}
bool judge(int ans,int q) {
    for(int i=1; i<=N-ans+1; ++i) {
        if( query(i,i+ans-1)<=q ) return true;
    }
    return false;
}
void getint(int &x){
    x=0;
    char ch=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}
int main() {
    //freopen("in.cpp","r",stdin);
    prep();
    while(~scanf("%d%d",&N,&M)) {
        if(N==0&&M==0) break;
        init();
        for(int i=0; i<N-1; ++i) {
            int a,b,c;
//            scanf("%d%d%d",&a,&b,&c);
            getint(a);
            getint(b);
            getint(c);
            insert(a,b,c);
            insert(b,a,c);
        }
        dfs(1,0);
        dfs(1,0,0,1);

        rmq();

        int maxLen = 0;
        for(int i=1; i<=N; ++i) {
            //printf("i=%d %d\n",i,ans[i]);
            if(maxLen<ans[i])   maxLen=ans[i];
        }

        while(M--) {
            int Q;
//            scanf("%d",&Q);
            getint(Q);
            int l=1,r=N,m;
            int ret = 1;
            while(l<=r) {
                m=(l+r)/2;
                if(judge(m,Q)) {
                    ret = m;
                    l=m+1;
                } else {
                    r = m-1;
                }
            }
            printf("%d\n",ret);
        }
    }
    return 0;
}
