#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,d;
int a[30][30];
int q[30][30];
bool inq[30][30];
bool check(){
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(a[i][j]) return false;
    return true;
}
bool doit(){
    memset(inq,false,sizeof(inq));
    while(1){
        int flag=0,x,y;
        for(int i=0;i<n;i++){
            if(flag) break;
            for(int j=0;j<m;j++){
                if(a[i][j]==1&&!inq[i][j]) x=i, y=j, flag=1;
                if(flag) break;
            }
        }

        if(flag==0) break;
        inq[x][y]=true;

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int dd=abs(i-x)+abs(j-y);
            if(dd==0||dd==d) a[i][j]^=1;
        }
    }
    return check();
}
int main(){
    freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d",&m,&n,&d)&&n+m+d){
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]);
        if(doit()) puts("1");
        else puts("0");
    }
    return 0;
}
