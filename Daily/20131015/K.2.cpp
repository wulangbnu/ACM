#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N=200000+10;
vector<int> adj[N];
int tot,m,n;
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){
        x=min(_x,_y);
        y=max(_x,_y);
    }
    bool operator < (const Point &tt) const{
        if(x!=tt.x) return x<=tt.x;
        return y<tt.y;
    }
    bool operator == (const Point &tt) const{
        return x==tt.x&&y==tt.y;
    }
};
vector<Point> p;
void input(){
    p.clear();
    vector<int> s;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        p.push_back(Point(x,y));
        s.push_back(x);
        s.push_back(y);
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    n=p.size();
    for(int i=0;i<n;i++){
        p[i].x=binary_search(s.begin(),s.end(),p[i].x);
        p[i].y=binary_search(s.begin(),s.end(),p[i].y);
        printf("%d %d\n",p[i].x,p[i].y);
    }
}
int main(){
    freopen("K.in.cpp","r",stdin);
    while(scanf("%d%d",&tot,&m)&&(tot+m)){
        input();
    }
    return 0;
}
