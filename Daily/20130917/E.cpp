#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double EPS=1e-8;
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    double dis2(){
        return x*x+y*y;
    }
}p[3],q;
double cross(Point p1,Point p2){
    return p1.x*p2.y-p1.y*p2.x;
}
double mut(Point p1,Point p2){
    return p1.x*p2.x+p1.y*p2.y;
}
Point sub(Point p1,Point p2){
    return Point(p1.x-p2.x,p1.y-p2.y);
}
void doit(double &xx,double &yy){
    double tmp=cross(sub(p[0],p[1]),sub(p[1],p[2]));
    tmp=2*tmp*tmp;
    double x=sub(p[1],p[2]).dis2()*mut(sub(p[0],p[1]),sub(p[0],p[2]))/tmp;
    double y=sub(p[0],p[2]).dis2()*mut(sub(p[1],p[0]),sub(p[1],p[2]))/tmp;
    double z=sub(p[0],p[1]).dis2()*mut(sub(p[2],p[0]),sub(p[2],p[1]))/tmp;
    xx=x*p[0].x+y*p[1].x+z*p[2].x;
    yy=x*p[0].y+y*p[1].y+z*p[2].y;
}
double dist(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    double x,y,r1;
    while(T--){
        for(int i=0;i<3;i++) p[i].input();
        q.input();
        double a=dist(p[1],p[2]), b=dist(p[0],p[2]), c=dist(p[0],p[1]);
        if(a*a>b*b+c*c+EPS){
            x=(p[1].x+p[2].x)/2;
            y=(p[1].y+p[2].y)/2;
            r1=dist(p[1],Point(x,y));
        }else if(b*b>a*a+c*c+EPS){
            x=(p[0].x+p[2].x)/2;
            y=(p[0].y+p[2].y)/2;
            r1=dist(p[0],Point(x,y));
        }else if(c*c>a*a+b*b+EPS){
            x=(p[0].x+p[1].x)/2;
            y=(p[0].y+p[1].y)/2;
            r1=dist(p[0],Point(x,y));
        }else{
            doit(x,y);
            r1=dist(p[0],Point(x,y));
        }
//        double r2=dist(p[1],Point(x,y));
//        double r3=dist(p[2],Point(x,y));
//        cout<<r1<<" "<<r2<<" "<<r3<<endl;
//        cout<<q.x<<" "<<q.y<<" "<<x<<" "<<y<<endl;
//        double tmp=dist(q,Point(x,y));
//        cout<<tmp<<endl;
        printf("Case #%d: ",cas++);
        if(dist(q,Point(x,y))<r1+EPS) puts("Danger");
        else puts("Safe");
    }
    return 0;
}
