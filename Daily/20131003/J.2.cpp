#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include<queue>
#include<set>
#include<vector>
using namespace std;
const int maxn=30;
typedef long long ll;

int n;
int st,nd;

int yc[1<<20][10];
vector<int>e[maxn];
struct P {
    int x,y,z,d;
    P() {}
    P(int _x,int _y,int _z,int _d) {
        x=_x,y=_y,z=_z,d=_d;
    }
    bool operator<(const P&a)const {
        if(x==a.x) {
            if(y==a.y)return z<a.z;
            return y<a.y;
        }
        return x<a.x;
    }
};

void init() {
    st|=(1<<0),st|=(1<<1),st|=(1<<2);
    nd|=(1<<3),nd|=(1<<4),nd|=(1<<5);
    for(int i=0; i<maxn; i++)e[i].clear();
}

inline ll syhash(int &x,int &y,int &z) {
    ll ret=0;
    ret|=x,ret|=(y<<20),ret|=(z<<40);
    return ret;
}
set<ll>sy;

//P que[5000005];
queue<P>que;
int bfs(int si) {
    while(!que.empty())que.pop();
    sy.clear();
    int fr=0,rr=0;
    P u,v;
    u=P(st,nd,si,0);
    sy.insert(syhash(st,nd,si));
    // que[rr++]=u;
    que.push(u);
    while(!que.empty()) {
        //u=que[fr++];
        u=que.front();
        que.pop();
        if(u.x==nd&&u.y==st)return u.d;
        if(u.z==0) {
            for(int k=0; k<3; k++) {
                int i=yc[u.x][k];
                for(int jj=0; jj<e[i].size(); jj++) {
                    int j=e[i][jj];
                    if(u.x&(1<<j))continue;
                    if(u.y&(1<<j))continue;
                    v.x=u.x-(1<<i)+(1<<j);
                    v.y=u.y;
                    v.d=u.d+1;
                    v.z=1-u.z;
                    ll tt=syhash(v.x,v.y,v.z);
                    if(sy.count(tt)==0) {
                        // sy[tt]=1;
                        sy.insert(tt);
                        //que[rr++]=v;
                        que.push(v);
                    }
                }
            }
        } else {
            for(int k=0; k<3; k++) {
                int i=yc[u.y][k];
                for(int jj=0; jj<e[i].size(); jj++) {
                    int j=e[i][jj];
                    if(u.y&(1<<j))continue;
                    if(u.x&(1<<j))continue;
                    v.x=u.x;
                    v.y=u.y-(1<<i)+(1<<j);
                    v.d=u.d+1;
                    v.z=1-u.z;
                    ll tt=syhash(v.x,v.y,v.z);
                    if(sy.count(tt)==0) {
                        //que[rr++]=v;
                        sy.insert(tt);
                        que.push(v);
                    }
                }
            }
        }
    }
    return -1;
}

int pd(int &ret,int val) {
    if(ret==-1)ret=val;
    ret=min(ret,val);
}
char str[100000];
string ss;
int main() {


    for(int i=0; i<(1<<20); i++) {
        int cnt=0;
        for(int j=0; j<20; j++)
            if(i&(1<<j)) {
                yc[i][cnt++]=j;
                if(cnt==4)break;
            }
    }

    //freopen("in.cpp","r",stdin);

    while(gets(str)) {
        init();
        istringstream in(str);
        while(in>>ss) {
            for(int i=1; i<ss.size(); i++) {
                int u=ss[0]-'a';
                int v=ss[i]-'a';
                e[u].push_back(v);
                e[v].push_back(u);
            }
        }
        int ret=-1;
        pd(ret,bfs(0));
        pd(ret,bfs(1));
        if(ret==-1)printf("No solution.\n");
        else printf("%d\n",ret);
    }
    return 0;
}
