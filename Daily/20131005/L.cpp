#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=20;
char str[N][N];
int n;
bool get[N][N];
int dir[][2]={0,1, 0,-1, -1,0, 1,0, 1,1, 1,-1, -1,1, -1,-1 };
void fill(int x,int y){
    if(get[x][y]) return;
    get[x][y]=true;
    if(str[x][y]!='0') return;
    for(int i=0;i<8;i++){
        int xx=x+dir[i][0], yy=y+dir[i][1];
        if(xx>=0&&xx<n&&yy>=0&&yy<n) fill(xx,yy);
    }
}
int doit(){
    memset(get,false,sizeof(get));
    int ans=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        if(str[i][j]=='0'&&!get[i][j]){
            ans++;
            fill(i,j);
        }
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        if(get[i][j]||str[i][j]=='@') continue;
        ans++;
    }
    return ans;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        printf("Case %d: %d\n",cas++,doit());
    }
    return 0;
}
