#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=10;
const int M=9;
struct Point{
    int type,x,y;
}p[N];
int n;
int dd[4][2]={0,1, 0,-1, 1,0, -1,0};
int dir[8][2]={1,2, 1,-2, -1,2, -1,-2, 2,1, 2,-1, -2,1, -2,-1};
bool check(int x,int y){
    return x>=1&&x<=N&&y>=1&&y<=M;
}
int doit(char ch){
    if(ch=='G') return 0;
    if(ch=='R') return 1;
    if(ch=='H') return 2;
    if(ch=='C') return 3;
    return -1;
}
bool che(int x,int y,int s,int t){
    if(x==s&&y==t) return true;
    if(x==s){
        for(int i=0;i<n;i++)
        if(p[i].x==s&&p[i].y>min(y,t)&&p[i].y<max(y,t)) return true;
        return false;
    }
    if(y==t){
        for(int i=0;i<n;i++)
        if(p[i].y==t&&p[i].x>min(x,s)&&p[i].x<max(x,s)) return true;
        return false;
    }
    return true;
}
bool ma(int x,int y,int s,int t){
    if(x==s&&y==t) return true;
    for(int i=0;i<8;i++){
        int xx=s+dir[i][0], yy=t+dir[i][1];
        if(!check(xx,yy)) continue;
        if(xx!=x||yy!=y) continue;


        int _x=-1,_y=-1;

        if(dir[i][0]==-2){
            _x=s-1; _y=t;
        }else if(dir[i][0]==2){
            _x=s+1; _y=t;
        }
        if(dir[i][1]==-2){
            _x=s; _y=t-1;
        }else if(dir[i][1]==2){
            _x=s; _y=t+1;
        }

        int f=0;
        for(int j=0;j<n;j++)
        if(p[j].x==_x&&p[j].y==_y) f=1;

        if(f==0) return false;
    }
    return true;
}
bool pao(int x,int y,int s,int t){
    if(x==s&&y==t) return true;
    if(x==s){
        int cnt=0;
        for(int i=0;i<n;i++)
        if(p[i].x==s&&p[i].y>min(y,t)&&p[i].y<max(y,t)) cnt++;
        if(cnt==1) return false;
        else return true;
    }
    if(y==t){
        int cnt=0;
        for(int i=0;i<n;i++)
        if(p[i].y==t&&p[i].x>min(x,s)&&p[i].x<max(x,s)) cnt++;
        if(cnt==1) return false;
        else return true;
    }
    return true;
}
bool solve(int x,int y){
    for(int i=0;i<n;i++){
        if(p[i].type==0){
            if(p[i].y==y){
              int f=0;
              for(int j=0;j<n;j++)
              if(p[j].y==y&&p[j].x>min(x,p[i].x)&&p[j].x<max(x,p[i].x)) f=1;
              if(f==0) return false;
            }
        }else if(p[i].type==1){
            if(!che(x,y,p[i].x,p[i].y)) return false;
        }else if(p[i].type==2){
            if(!ma(x,y,p[i].x,p[i].y)) return false;
        }else if(p[i].type==3){
            if(!pao(x,y,p[i].x,p[i].y)) return false;
        }
    }
    return true;
}
bool work(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dd[i][0], yy=y+dd[i][1];
        if(check(xx,yy)&&xx<=3&&yy>=4&&yy<=6&&solve(xx,yy)) return true;
    }
    return false;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int x,y;
    while(scanf("%d%d%d",&n,&x,&y)&&n){
//        printf("%d %d %d\n",n,x,y);
        for(int i=0;i<n;i++){
            char str[5];
            scanf("%s",str);
            p[i].type=doit(str[0]);
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        if(work(x,y)) puts("NO");
        else puts("YES");
    }
    return 0;
}
