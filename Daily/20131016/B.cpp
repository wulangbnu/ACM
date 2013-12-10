#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N=100+10;
int g[N][N],n,m;
struct Point{
    int x,v;
    Point(int _x=0,int _v=0){
        x=_x; v=_v;
    }
    bool operator <(const Point &tt) const{
        if(v!=tt.v) return v<tt.v;
        return  x<tt.x;
    }
};
int a[N*N],pre[N*N][2],type[N*N];
void solve(){
    memset(a,0,sizeof(a));
    memset(pre,-1,sizeof(pre));
    memset(type,-1,sizeof(type));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        int x=g[i][j];
        a[x]++;
        if(pre[x][0]==i) type[x]=0;
        if(pre[x][1]==j) type[x]=1;
        pre[x][0]=i;
        pre[x][1]=j;
    }
    priority_queue<Point> q[2];
    for(int i=0;i<N*N;i++){
        if(a[i]==0) continue;
        if(type[i]!=-1) q[type[i]].push(Point(i,a[i]));
        else{
            q[0].push(Point(i,a[i]));
            q[1].push(Point(i,a[i]));
        }
    }
    vector<int> ans;
    memset(a,0,sizeof(a));
    while(!q[0].empty()||!q[1].empty()){
        while(!q[0].empty()&&a[q[0].top().x]) q[0].pop();
        while(!q[1].empty()&&a[q[1].top().x]) q[1].pop();
        int x=-1,y;
        if(!q[0].empty()&&q[0].top().v==m){
            x=q[0].top().x;
            q[0].pop();
            y=0;
        }
        else if(!q[1].empty()&&q[1].top().v==n){
            x=q[1].top().x;
            q[1].pop();
            y=1;
        }
        //printf("!! %d %d %d\n",x,n,m);
        if(x!=-1&&a[x]==0){
            ans.push_back(x);
            if(y==0) n--;
            else m--;
            a[x]++;
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
    printf("%d%c",ans[i],i==0?'\n':' ');
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)&&(n+m)){
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&g[i][j]);

        solve();
    }
    return 0;
}
