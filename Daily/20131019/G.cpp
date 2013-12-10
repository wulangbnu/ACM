#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define clear(a,x) memset(a,(x),sizeof(a))
using namespace std;
int N,M,Q;
int a[10][10];
int ans;
bool judge(int x,int y){
    //hang
    bool mid = false;
    for(int i=y-1; i>=1; --i){
        if(a[x][i]==0) continue;
        if(a[x][i]==1&&mid) return false;
        if(mid) break;
        mid = true;
    }

    //lie
    mid = false;
    for(int i=x-1; i>=1; --i){
        if(a[i][y]==0) continue;
        if(a[i][y]==1&&mid) return false;
        if(mid) break;
        mid = true;
    }

    return true;
}

void dfs(int x,int y,int n){
    //printf("%d %d %d\n",x,y,n);
    ans=max(n,ans);
    if(y>M){
        x++; y=1;
    }
    if(x>N) return;
    if( a[x][y]==0 ){
        if(judge(x,y)){
            a[x][y] = 1;
            dfs(x,y+1,n+1);
            a[x][y] = 0;
        }
        a[x][y] = 0;
        dfs(x,y+1,n);
        a[x][y] = 0;
    }
    else dfs(x,y+1,n);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&Q)){
        clear(a,0);
        for(int i=0; i<Q; ++i){
            int x,y;
            scanf("%d%d",&x,&y);
            x++; y++;
            a[x][y] = -1;
        }
        ans = 0;
        dfs(1,1,0);
        printf("%d\n",ans);
    }
    return 0;
}
