#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N=20+10;
char str[N][N];
int n;
bool doit(){
    int cnt=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cnt+=(str[i][j]=='#');
    int x,y;
    for(x=0;x<n;x++){
        for(y=0;y<n;y++) if(str[x][y]=='#') break;
        if(y<n) break;
    }

    int t;
    for(t=y;t<n;t++) if(str[x][t]!='#') break;
    t-=y;

    //printf("%d %d %d %d\n",cnt,x,y,t);

    if(t*t!=cnt) return false;
    if(y+t>n) return false;

    for(int i=x;i<x+t;i++)
    for(int j=y;j<y+t;j++)
    if(str[i][j]!='#') return false;
    return true;

}
int main(){
    #ifdef wulang
        freopen("square_detector.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        if(doit()) printf("Case #%d: YES\n",++cas);
        else printf("Case #%d: NO\n",++cas);
    }
    return 0;
}
