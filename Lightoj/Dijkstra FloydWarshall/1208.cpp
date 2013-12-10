#include <cstdio>
#include <algorithm>
#include <cmath>
#define PI 3.1415926
using namespace std;
int top=0;
struct Point{
	int  x;
	int  y;

};
Point p[1005],s[1005];
int  cross(Point &a, Point &b)
{
	return a.x * b.y - a.y * b.x;
}


int dir( Point p0, Point p1, Point p2)
{
	Point px, py;
	px.x=p1.x-p0.x;
	px.y=p1.y-p0.y;
	py.x=p2.x-p0.x;
	py.y=p2.y-p0.y;
	return cross(px, py);
}

double dis(const Point s1,const Point s2)
{
	return sqrt((s1.x-s2.x)*(s1.x-s2.x)+(s1.y-s2.y)*(s1.y-s2.y));
}

bool cmp( Point p1,  Point p2)
{
    Point p0=p[0];
    if(dir(p0,p1,p2)) return dir(p0,p1,p2)>0;
	else return dis(p1,p0)<dis(p2,p0);
}
void push(int i)
{
    s[++top]=p[i];
}

void pop()
{
    top--;
}


int main()
{
    freopen("in.cpp","r",stdin);

    int n,pbase=0,l,i,j,k;
    double ans=0;
    int T;
    scanf("%d",&T);
    while(T--)
    {

      top=pbase=0;
    scanf("%d %d %d",&n,&j,&k);
    n*=2;
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].x);
        scanf("%d",&p[i].y);
        if(p[i].y<p[pbase].y) pbase=i;
        else if((p[i].y==p[pbase].y)&&(p[i].x<p[pbase].x)) pbase=i;
    }
    Point tmp;
    tmp=p[pbase];
    p[pbase]=p[0];
    p[0]=tmp;
    sort(p+1,p+n,cmp);
    top=2;
    s[0]=p[0];s[1]=p[1];s[2]=p[2];

    for (i=3;i<n;i++)
        {
            while( top>=1 && dir(s[top-1], s[top],p[i])<=0 ) pop();
            push(i);
        }

    for(ans=0,i=0;i<=top-1;i++)
        ans+=dis(s[i],s[i+1]);
       ans+=dis(s[0],s[top]);
       printf("%.0f\n",ans);

       }
      return 0;
}

