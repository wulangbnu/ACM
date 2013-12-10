#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=10;
bool a[N][N];
int n;
int dir[][2]= {2,1,  2,-1, -2,1, -2,-1, 1,-2, 1,2, -1,-2, -1,2};
bool check(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<n;
}
void output(bool flag) {
    for(int i=0; i<n; i++,puts(""))
        for(int j=0; j<n; j++) {
            if(a[i][j]) printf("-");
            else printf("*");
        }
    if(flag) puts("1");
    else puts("0");

}
bool dfs() {

    bool flag=false;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            if(a[i][j]) continue;

            a[i][j]=true;
            int cnt=0;
            int x[8],y[8];
            for(int k=0; k<8; k++) {
                int xx=i+dir[k][0],yy=j+dir[k][1];
                if(check(xx,yy)&&!a[xx][yy]) {
                    a[xx][yy]=true;
                    x[cnt]=xx;
                    y[cnt++]=yy;
                }
            }

            if(!dfs()) flag=true;

            a[i][j]=false;
            for(int k=0; k<cnt; k++) a[x[k]][y[k]]=false;

            if(flag) {
                //output(flag);
                return true;
            }

        }
    //output(flag);
    return flag;
}
int main() {
    //freopen("out.cpp","w",stdout);
    //n=3;
    // memset(a,false,sizeof(a));
    // output(true);
    //printf("%d\n",dfs());
    for(n=1; n<N; n++) {
        memset(a,false,sizeof(a));
        if(!dfs()) printf("%d\n",n);
    }
    return 0;
}
