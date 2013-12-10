#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N=10+10;
template <class T>
struct Point{
    T x,y;
    Point(T _x=0,T _y=0):x(_x),y(_y){}
    bool operator <(const Point &tt) const{
        return x<tt.x;
    }
};
Point<int> q;
typedef vector<Point<int> > vp;
vp p[N];
int dir[][2]={0,1, 1,0,  0,-1,  -1,0};
int n;
void input(vp &p){
    p.clear();
    int k,x,y,d=0;
    char str[5];
    scanf("%d%d%d",&k,&x,&y);
    p.push_back(Point<int>(x,y));
    while(k--){
        scanf("%s",str);
        if(str[0]=='L') d=(d+3)%4;
        else if(str[0]=='R') d=(d+1)%4;
        else{
            int len;
            scanf("%d",&len);
            x+=len*dir[d][0];
            y+=len*dir[d][1];
            p.push_back(Point<int>(x,y));
        }
    }
}
void doit(vp &p){
    for(int i=0;i<p.size()-1;i++){
        double x=atan2((p[i].y-q.y),(p[i].x-q.x));
        double y=atan2((p[i].y-q.y),(p[i].x-q.x));
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&q.x,&q.y);
        for(int i=0;i<n;i++) input(p[i]);
        for(int i=0;i<n;i++) doit(p[i]);
    }
    return 0;
}
