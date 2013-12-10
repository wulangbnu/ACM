#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const double EP = 1e-6;
struct POINT
{
    double x,y;
} p[200];
double dist(POINT a,POINT b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
bool cocircle(POINT p1,POINT p2,POINT p3,POINT &q,double &r)
{
    double x12=p2.x-p1.x;
    double y12=p2.y-p1.y;
    double x13=p3.x-p1.x;
    double y13=p3.y-p1.y;
    double z2=x12*(p1.x+p2.x)+y12*(p1.y+p2.y);
    double z3=x13*(p1.x+p3.x)+y13*(p1.y+p3.y);
    double d=2.0*(x12*(p3.y-p2.y)-y12*(p3.x-p2.x));
    if(fabs(d)<EP)
        return false;

    //printf("d=%f\n",fabs(d));

    q.x=(y13*z2-y12*z3)/d;
    q.y=(x12*z3-x13*z2)/d;
    r=dist(p1,q);
    return true;
}

int main()
{
    //freopen("in.cpp","r",stdin);
    int N;
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        for(int i=0; i<N; ++i)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        if(N<=2)
        {
            printf("%d\n",N);
            continue;
        }
        int ans = 2;
        POINT q;
        double r;
        for(int i=0; i<N; ++i)
            for(int j=i+1; j<N; ++j)
                for(int k=j+1; k<N; ++k)
                {
                    bool flag = cocircle(p[i],p[j],p[k],q,r);
                    if(flag == false) continue;
                    int t = 0;
                    for(int ii=0; ii<N; ++ii)
                    {
                        double tt = dist(p[ii],q);
                        if(   fabs(tt-r) < EP )
                            t++;
                    }
                    if(ans<t) ans = t;
                }
        printf("%d\n",ans);
    }
    return 0;
}
