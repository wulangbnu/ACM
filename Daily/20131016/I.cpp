#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int N,M;
map<string,int>chash;
const double INF = 1e8;
const double EPS = 1e-8;
double adj[210][210];
void solve() {
    for(int k=0; k<N; ++k)
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                if( adj[i][j]>adj[i][k]+adj[k][j] ) {
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
}
int main() {
    //freopen("in.cpp","r",stdin);
    while(~scanf("%d",&M)) {
        if(M==0) break;
        N=0;
        for(int i=0; i<210; ++i)
            for(int j=0; j<210; ++j)
                adj[i][j] = (i==j?0:INF);
        chash.clear();
        while(M--) {
            double a,b;
            string x,y;

            //scanf("%lf%d%lf%d",&a,&x,&b,&y);
            cin>>a>>x>>b>>y;
            if(chash.find(x)==chash.end()) {
                chash[x]=N++;
            }
            if(chash.find(y)==chash.end()) {
                chash[y]=N++;
            }
            adj[chash[x]][chash[y]] = log(b/a);
        }

        solve();

        double a,b;
        string sx,sy;
        //scanf("%lf%d%lf%d",&a,&x,&b,&y);
        cin>>a>>sx>>b>>sy;
        if(chash.find(sx)==chash.end()) {
            chash[sx]=N++;
        }
        if(chash.find(sy)==chash.end()) {
            chash[sy]=N++;
        }
        int x = chash[sx];
        int y = chash[sy];

        bool isContradiction = false;
        for(int i=0; i<N; ++i) {
            if(adj[i][i]<-EPS) isContradiction = true;
        }
        if(isContradiction) {
            printf("INCONSISTENT\n");
        } else {
            //printf("%f %f %f %f\n",adj[x][y],b/a,adj[y][x],a/b);
            if(fabs(adj[x][y]-log(b/a))<EPS && fabs(adj[y][x]-log(a/b))<EPS) printf("==\n");
            else if(adj[x][y] < log(b/a)+EPS) printf("<=\n");
            else if(adj[y][x] < log(a/b)+EPS) printf(">=\n");
            else printf("UNAVAILABLE\n");
        }
    }
    return 0;
}
