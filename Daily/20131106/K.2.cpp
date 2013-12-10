#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <map>
#define maxn 505
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

map<int,int> tox;
map<int,int> toy;

int N;
int sx,sy,tx,ty;

vector<int> vx;
vector<int> vy;

int x1[maxn],x2[maxn],y1[maxn],y2[maxn];
int n,m;
bool flag[1100][1100];
int d[1100][1100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void prepare() {
    tox.clear();
    toy.clear();
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());

    sort(vy.begin(),vy.end());
    vy.erase(unique(vy.begin(),vy.end()),vy.end());

    int sz = vx.size();
    int pos = 2;
    tox[vx[0]]=2;
    for (int i=1; i<sz; i++) {
        pos+=2;
        tox[vx[i]]=pos;
    }

    n = pos+3;

    sz = vy.size();
    pos = 2;
    toy[vy[0]]=2;
    for (int i=1; i<sz; i++) {
        pos+=2;
        toy[vy[i]]=pos;
    }
    m = pos+3;

    sx = tox[sx];
    tx = tox[tx];
    sy = toy[sy];
    ty = toy[ty];

    for (int i=1; i<=N; i++) {
        x1[i]=tox[x1[i]];
        x2[i]=tox[x2[i]];
        y1[i]=toy[y1[i]];
        y2[i]=toy[y2[i]];
    }
}

bool check(int x,int y) {
    if (x<0||x>=n) return false;
    if (y<0||y>=m) return false;
    return true;
}

int work() {
    for (int i=0; i<=n+1; i++)
        for (int j=0; j<=m+1; j++) {
            flag[i][j]=true;
            d[i][j]=oo;
        }

    for (int k=1; k<=N; k++) {
        for (int i=x1[k]; i<=x2[k]; i++)
            flag[i][y1[k]]=flag[i][y2[k]]=false;

        for (int i=y1[k]; i<=y2[k]; i++)
            flag[x1[k]][i]=flag[x2[k]][i]=false;
    }

    int ans = oo;

    for(int i=0;i<n;i++,puts(""))
    for(int j=0;j<m;j++){
        if(i==sx&&j==sy) printf("S");
        else if(i==tx&&j==ty) printf("T");
        else if(flag[i][j]) printf("*");
        else printf(" ");
    }
    printf("### %d %d %d %d\n",sx,sy,tx,ty);
    queue<int> q;
    d[sx][sy]=0;
    q.push(sx*m+sy);

    int x,y;
    int now;
    int qx,qy;

    while (!q.empty()) {
        now = q.front();
        q.pop();
        x = now/m;
        y = now%m;

        int cnt=0;
        for (int i=0; i<4; i++) {
            qx = x+dx[i];
            qy = y+dy[i];
            while (check(qx,qy)&&flag[qx][qy]) {
                if (d[qx][qy]==oo) {
                    d[qx][qy]=d[x][y]+1;
                    q.push(qx*m+qy);
                    //printf("~~~~ %d %d %d\n",qx,qy,d[qx][qy]);
                }
                qx = qx+dx[i];
                qy = qy+dy[i];
                cnt++;
            }

//            puts("********************");
//            printf("~ %d %d %d\n",x,y,i);
//            for(int ii=0;ii<n;ii++,puts(""))
//            for(int jj=0;jj<m;jj++){
//                if(flag[ii][jj]&&d[ii][jj]<10) printf("%d",d[ii][jj]);
//                else printf(" ");
//            }

        }
        printf("!!!%d\n",cnt);
        //if (d[tx][ty]!=oo) return d[tx][ty];
    }

    puts("********************");
    for(int i=0;i<n;i++,puts(""))
    for(int j=0;j<m;j++){
        if(flag[i][j]&&d[i][j]<10) printf("%d",d[i][j]);
        else printf(" ");
    }

    return d[tx][ty]-1;
}

int main() {

    freopen("in.cpp","r",stdin);
    freopen("out.cpp","w",stdout);
    while (scanf("%d%d%d%d%d",&N,&sx,&sy,&tx,&ty)==5) {
        vx.clear();
        vy.clear();
        vx.push_back(sx);
        vx.push_back(tx);
        vy.push_back(sy);
        vy.push_back(ty);
        printf("### %d %d %d %d\n",sx,sy,tx,ty);

        for (int i=1; i<=N; i++) {
            scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
            vx.push_back(x1[i]);
            vx.push_back(x2[i]);
            vy.push_back(y1[i]);
            vy.push_back(y2[i]);
        }

        prepare();

        cout << work() <<endl;

    }

    return 0;
}
