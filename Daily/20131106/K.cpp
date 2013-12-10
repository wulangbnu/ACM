#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=2000+10;
const int INF=10000+10;
bool g[N][N];
short int a[2000+10];
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
    a[cnt++]=INF;
    a[cnt++]=-INF;
    for(int i=0;i<n;i++){
        a[cnt++]=re[i].x1-1;
        a[cnt++]=re[i].x1;
        a[cnt++]=re[i].x2;
        a[cnt++]=re[i].x2+1;
    }
    sort(a,a+cnt);
    cnt=unique(a,a+cnt)-a;
    sx=lower_bound(a,a+cnt,sx)-a;
    tx=lower_bound(a,a+cnt,tx)-a;
    for(int i=0;i<n;i++){
        re[i].x1=lower_bound(a,a+cnt,re[i].x1)-a;
        re[i].x2=lower_bound(a,a+cnt,re[i].x2)-a;
    }
    cnt1=cnt;


    cnt=0;
    a[cnt++]=sy;
    a[cnt++]=ty;
    a[cnt++]=INF;
    a[cnt++]=-INF;
    for(int i=0;i<n;i++){
        a[cnt++]=re[i].y1-1;
        a[cnt++]=re[i].y1;
        a[cnt++]=re[i].y2;
        a[cnt++]=re[i].y2+1;
    }
    sort(a,a+cnt);
    cnt=unique(a,a+cnt)-a;
    sy=lower_bound(a,a+cnt,sy)-a;
    ty=lower_bound(a,a+cnt,ty)-a;
    for(int i=0;i<n;i++){
        re[i].y1=lower_bound(a,a+cnt,re[i].y1)-a;
        re[i].y2=lower_bound(a,a+cnt,re[i].y2)-a;
    }
    cnt2=cnt;
}
void work(){
    memset(g,true,sizeof(g));
    for(int i=0;i<n;i++){
        int x=re[i].x1;
        int y=re[i].x2;
        for(int j=x;j<=y;j++){
            g[j][re[i].y1]=false;
            g[j][re[i].y2]=false;
        }
        x=re[i].y1;
        y=re[i].y2;
        for(int j=x;j<=y;j++){
            g[re[i].x1][j]=false;
            g[re[i].x2][j]=false;
        }
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
            if(d[x][y][z]+1<d[x][y][(z+i)%4]){
                d[x][y][(z+i)%4]=d[x][y][z]+1;
                if(!inq[x][y][(z+i)%4]){
                    q.push(Point(x,y,(z+i)%4));
                    inq[x][y][(z+i)%4]=true;
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
