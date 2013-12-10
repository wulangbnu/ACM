#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int N=300+10;
const int INF=0x3f3f3f3f;
char str[N][N];
int n,m,d[N][N];
bool inq[N][N];
int dir[][2]={-1,0, 1,0, 0,1, 0,-1};
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y){
        x=_x; y=_y;
    }
};
bool check(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
int spfa(int x,int y){
    memset(d,0x3f,sizeof(d));
    memset(inq,false,sizeof(inq));
    d[x][y]=0;
    queue<Point> q;
    q.push(Point(x,y));
    inq[x][y]=true;
    int ans=INF;
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        x=p.x, y=p.y;
        inq[x][y]=false;
        if(str[x][y]=='T') ans=min(ans,d[x][y]);
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0], yy=y+dir[i][1];
            if(!check(xx,yy)||str[xx][yy]=='S'||str[xx][yy]=='R') continue;
            int val=d[x][y]+1+(str[xx][yy]=='B');
            if(val<d[xx][yy]){
                d[xx][yy]=val;
                if(!inq[xx][yy]){
                    q.push(Point(xx,yy));
                    inq[xx][yy]=true;
                }
            }
        }
    }
    if(ans==INF) return -1;
    return ans;
}
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)&&n+m){
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(str[i][j]=='Y') printf("%d\n",spfa(i,j));
    }
    return 0;
}
