#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000+10;
const int INF=0x3f3f3f3f;
int g[N][N][2],d[N][2];
int q[N];
bool inq[N];
int n,m,s,t;
void init(){
    memset(g,0x3f,sizeof(g));
    memset(d,0x3f,sizeof(d));
}
void spfa(){
    memset(inq,false,sizeof(inq));
    d[s][0]=d[s][1]=0;
    int l=0,r=0;
    q[r++]=s;
    inq[s]=true;
    while(l!=r){
        int x=q[l++];
        if(l>=N) l=0;
        inq[x]=false;
        for(int y=1;y<=n;y++){
            if(d[x][0]+g[x][y][0]<d[y][0]||(d[x][0]+g[x][y][0]==d[y][0]&&d[x][1]+g[x][y][1]<d[y][1])){
                d[y][0]=d[x][0]+g[x][y][0];
                d[y][1]=d[x][1]+g[x][y][1];
                if(!inq[y]){
                    q[r++]=y;
                    if(r>=N) r=0;
                    inq[y]=true;
                }
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m)&&n+m){
        init();
        while(m--){
            int a,b,c,p;
            scanf("%d%d%d%d",&a,&b,&c,&p);
            g[a][b][0]=min(g[a][b][0],c);
            g[a][b][1]=min(g[a][b][1],p);
        }
        scanf("%d%d",&s,&t);

        spfa();
        printf("%d %d\n",d[t][0],d[t][1]);

    }
    return 0;
}
