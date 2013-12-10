#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;
const int N=20;
const int M=1140+10;
const int INF=0x3f3f3f3f;
vector<int> adj[N];
int d[2][M][M],pre[3][M],next[N][N][N],cas;
int q[M*M*2];
void init(){
    for(int tot=0,i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
    for(int k=j+1;k<N;k++){
        pre[0][tot]=i;
        pre[1][tot]=j;
        pre[2][tot]=k;
        next[i][j][k]=next[i][k][j]=tot;
        next[j][i][k]=next[j][k][i]=tot;
        next[k][i][j]=next[k][j][i]=tot++;
    }
}
bool input(){
    char str[500];
    while(!gets(str)) return false;
    for(int i=0;i<N;i++) adj[i].clear();
    istringstream in(str);
    string ss;
    while(in>>ss){
        int i=ss[0]-'a';
        for(int j=1;j<ss.size();j++){
            int k=ss[j]-'a';
            adj[i].push_back(k);
            adj[k].push_back(i);
        }
    }
    return true;
}
void doit(int a,int b,int c,int val,int &r){
    int pos[3],tag[N];
    for(int i=0;i<3;i++) tag[pos[i]=pre[i][a]]=cas;
    for(int i=0;i<3;i++) tag[pre[i][b]]=cas;
    for(int i=0;i<3;i++)
    for(int x=pos[i],j=0;j<adj[x].size();j++){
        int y=adj[x][j];
        if(tag[y]==cas) continue;
        int s;
        if(i==0)      s=next[y][pos[1]][pos[2]];
        else if(i==1) s=next[y][pos[0]][pos[2]];
        else          s=next[y][pos[0]][pos[1]];
        if(c&&val+1<d[c^1][s][b]){
            d[c^1][s][b]=val+1;
            q[r++]=s|(b<<11);
        }
        if(!c&&val+1<d[c^1][b][s]){
            d[c^1][b][s]=val+1;
            q[r++]=b|(s<<11)|(1<<22);
        }
    }
    cas++;
}
int bfs(){
    memset(d,0x3f,sizeof(d));
    int l=0,r=0;
    int x=next[0][1][2]|(next[3][4][5]<<11);
    d[0][next[0][1][2]][next[3][4][5]]=0;
    q[r++]=x;
    x|=1<<22;
    d[1][next[0][1][2]][next[3][4][5]]=0;
    q[r++]=x;
    while(l!=r){
        x=q[l++];
        int a=x&((1<<11)-1), b=(x>>11)&((1<<11)-1), c=x>>22;
        if(a==next[3][4][5]&&b==next[0][1][2]) return d[c][a][b];
        if(c) doit(a,b,c,d[c][a][b],r);
        else  doit(b,a,c,d[c][a][b],r);
    }
    return -1;
}
int main(){
    //freopen("in.cpp","r",stdin);
    init();
    while(input()){
        int ans=bfs();
        if(ans==-1) puts("No solution.");
        else printf("%d\n",ans);
    }
    return 0;
}
