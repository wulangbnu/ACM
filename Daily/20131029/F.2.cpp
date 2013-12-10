#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int N=300000+10;
struct Point{
    double v;
    int t;
    bool operator < (const Point &tt) const{
        return t>tt.t;
    }
}p[N];
priority_queue<Point>q;
int n,m;
void run_time(){
    int k;
    for(k=0;k<n&&k<m;k++) q.push(p[k]);
    while(!q.empty()){
        int t=q.top().t;
        q.pop();
        if(k<n){
            p[k].t+=t;
            q.push(p[k]);
            k++;
        }
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)+1){
        for(int i=0;i<n;i++) scanf("%d%lf",&p[i].t,&p[i].v);
        run_time();
        double ans=0, base=0;
        int t=0;
        for(int i=0;i<n;i++){
            t=max(t,p[i].t);
           // printf("~~ %d \n",t);
            if(i==n-1) ans+=exp(log(t*1.0)+base);
            else ans+=exp(log(t*1.0)+base)-exp(log(t*1.0)+base+log(p[i].v));
            base+=log(p[i].v);
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
