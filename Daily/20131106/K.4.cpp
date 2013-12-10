#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=2000+10;
const int M=10000+10;
const int INF=10000+10;
#define F(x) (x)=pre[(x)+M]
bool g[N][N];
short int a[2000+10],pre[2*M];
struct Rec{
    int x1,y1,x2,y2;
    void input(){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    }
}re[500+10];
struct Point{
    short int x,y,z;
    Point(int _x=0,int _y=0,int _z=0){
        x=_x;
        y=_y;
        z=_z;
    }
};

int n,cnt1,cnt2;
int sx,sy,tx,ty;
void doit(){
    int cnt=0;
    a[cnt++]=sx;
    a[cnt++]=tx;
    for(int i=0;i<n;i++){
        a[cnt++]=re[i].x1;
        a[cnt++]=re[i].x2;
    }
    sort(a,a+cnt);
    cnt=unique(a,a+cnt)-a;
    int tot=1;
    for(int i=0;i<cnt;i++){
        pre[a[i]+M]=tot;
        tot+=2;
    }
    cnt1=tot;

    F(sx);
    F(tx);
    for(int i=0;i<n;i++){
        F(re[i].x1);
        F(re[i].x2);
    }

    cnt=0;
    a[cnt++]=sy;
    a[cnt++]=ty;
    for(int i=0;i<n;i++){
        a[cnt++]=re[i].y1;
        a[cnt++]=re[i].y2;
    }
    sort(a,a+cnt);
    cnt=unique(a,a+cnt)-a;
    tot=1;
    for(int i=0;i<cnt;i++){
        pre[a[i]+M]=tot;
        tot+=2;
    }
    cnt2=tot;

    F(sy);
    F(ty);
    for(int i=0;i<n;i++){
        F(re[i].y1);
        F(re[i].y2);
    }
}
void work(){
    memset(g,true,sizeof(g));
    for(int i=0;i<n;i++){
        for(int j=re[i].x1;j<=re[i].x2;j++)
        g[j][re[i].y1]=g[j][re[i].y2]=false;

        for(int j=re[i].y1;j<=re[i].y2;j++)
        g[re[i].x1][j]=g[re[i].x2][j]=false;
    }
}
int dir[][2]={0,-1, 0,1,  -1,0, 1,0};
bool check(int x,int y){
    return x>=0&&x<cnt1&&y>=0&&y<cnt2&&g[x][y];
}
short int d[N][N][4];
bool inq[N][N][4];
void bfs(){
    memset(d,0x3f,sizeof(d));
    memset(inq,false,sizeof(inq));
    queue<Point> q;
    for(int i=0;i<4;i++){
        d[sx][sy][i]=0;
        q.push(Point(sx,sy,i));
        inq[sx][sy][i]=true;
    }
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        int x=p.x, y=p.y, z=p.z;
        inq[x][y][z]=false;
        for(int i=1;i<4;i++){
            int zz=(z+i)%4;
            if(d[x][y][z]+1<d[x][y][zz]){
                d[x][y][zz]=d[x][y][z]+1;
                if(!inq[x][y][zz]){
                    q.push(Point(x,y,zz));
                    inq[x][y][zz]=true;
                }
            }
        }

        int xx=x+dir[z][0], yy=y+dir[z][1];
        if(!check(xx,yy)) continue;
        if(d[x][y][z]<d[xx][yy][z]){
            d[xx][yy][z]=d[x][y][z];
            if(!inq[xx][yy][z]){
                q.push(Point(xx,yy,z));
                inq[xx][yy][z]=true;
            }
        }
    }
    int ans=INF;
    for(int i=0;i<4;i++) ans=min(ans,(int)d[tx][ty][i]);
    printf("%d\n",ans);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d%d%d",&n,&sx,&sy,&tx,&ty)+1){
        for(int i=0;i<n;i++) re[i].input();
        doit();
        work();
        bfs();
    }
    return 0;
}
