#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=8;
int str[N][N];
int ans,n,m;
int dir[][2]={-1,0, 1,0,  0,-1, 0,1};
bool get[5];
inline bool check2(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
bool check(int x,int y){

    if(!check2(x,y)) return true;
    memset(get,false,sizeof(get));

    for(int i=0;i<4;i++){
        int xx=x+dir[i][0], yy=y+dir[i][1];
        if(!check2(xx,yy)) continue;
        get[str[xx][yy]]=true;
    }

    for(int i=str[x][y]+1;i<=4;i++)
    if(!get[i]) return false;
    return true;
}
void dfs(int x,int y,int cnt){
    if(y==m){
        x++;
        y=0;
    }

    //printf("%d %d\n",x,y);

    if(cnt+m*(n-1-x)+m-y<=ans) return;
    if(x==n){
        for(int j=0;j<m;j++) if(!check(n-1,j)) return;
        ans=max(ans,cnt);
    }

    for(int i=1;i<=4;i++){
        str[x][y]=i;
        if(check(x-1,y)) dfs(x,y+1,cnt+(i==1));
    }
    str[x][y]=0;

}
int main(){
    //freopen("in.cpp","r",stdin);
//    n=2; m=2;
//    ans=0;
//    dfs(0,0,0);
//    printf("%d\n",ans);
    for(n=2;n<8;n++)
    for(m=n;m<8;m++){
        ans=0;
        dfs(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
