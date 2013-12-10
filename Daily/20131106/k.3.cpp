#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=2000+100;
const int INF=0x3f3f3f3f;
int g[N][N];
int a[N];
struct Rec{
    int x1,y1,x2,y2;
    void input(){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    }
}re[N];
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){
        x=_x;
        y=_y;
    }
};

int n,cnt1,cnt2;
int sx,sy,tx,ty;
void doit(){
    int cnt=0;
    a[cnt++]=-INF;
    a[cnt++]=INF;
    a[cnt++]=sx;
    a[cnt++]=tx;
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
    a[cnt++]=-INF;
    a[cnt++]=INF;
    a[cnt++]=sy;
    a[cnt++]=ty;
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
    memset(g,0x3f,sizeof(g));
    for(int i=0;i<n;i++){
        for(int j=re[i].x1;j<=re[i].x2;j++){
            g[j][re[i].y1]=-1;
            g[j][re[i].y2]=-1;
        }
        for(int j=re[i].y1;j<=re[i].y2;j++){
            g[re[i].x1][j]=-1;
            g[re[i].x2][j]=-1;
        }
    }
}
int dir[][2]={0,-1, 0,1,  -1,0, 1,0};
bool check(int x,int y){
    return x>=0&&x<cnt1&&y>=0&&y<cnt2&&g[x][y]!=-1;
}
bool inq[N][N];
int bfs(){

    memset(inq,false,sizeof(inq));
    g[sx][sy]=0;
    queue<Point> q;
    q.push(Point(sx,sy));
    inq[sx][sy]=true;

    while(!q.empty()){
        Point p=q.front();
        q.pop();
        int x=p.x, y=p.y;
        inq[x][y]=false;
        if(x==tx&&y==ty) return g[x][y];
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0], yy=y+dir[i][1];
            while(check(xx,yy)){
                if(g[xx][yy]<=g[x][y]) break;
                if(g[x][y]+1<g[xx][yy]){
                    g[xx][yy]=g[x][y]+1;
                    if(!inq[xx][yy]){
                        q.push(Point(xx,yy));
                        inq[xx][yy]=true;
                    }
                }
                xx+=dir[i][0];
                yy+=dir[i][1];
            }
        }
    }
    return g[tx][ty];
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d%d%d",&n,&sx,&sy,&tx,&ty)+1){
        for(int i=0;i<n;i++) re[i].input();
        doit();
        work();
        int ans=max(bfs()-1,0);
        printf("%d\n",ans);
    }
    return 0;
}
