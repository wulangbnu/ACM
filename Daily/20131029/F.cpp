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
    int id;
    bool operator < (const Point &tt) const{
        if(t!=tt.t) return t>tt.t;
        return id>tt.id;
    }
}p[N];
priority_queue<Point>q;
int n,m;
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)+1){
        for(int i=0;i<n;i++){
            scanf("%d%lf",&p[i].t,&p[i].v);
            p[i].id=i;
        }
        double base=0;
        double ans=0;
        int k=0;
        for(k=0;k<n&&k<m;k++) q.push(p[k]);
        while(!q.empty()){
            int t=q.top().t;
            double tot=0;
            int cnt=0;
            while(!q.empty()&&q.top().t==t){
                tot+=log(q.top().v);
                q.pop();
                cnt++;
                //break;
            }
            //one has wrong
            //ans+=t*exp(base)*(1.0-exp(tot));
            //all right
            //if(k==n&&q.empty()) ans+=t*exp(base+tot);

            if(k==n&&q.empty()) ans+=exp(log(t*1.0)+base);
            else ans+=exp(log(t*1.0)+base)-exp(log(t*1.0)+base+tot);

            base+=tot;

            while(k<n&&cnt>0){
                p[k].t+=t;
                q.push(p[k]);
                k++;
                cnt--;
            }
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
