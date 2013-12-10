#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=200+10;
int x[N],y[N],n,x1,y1,x2,y2;
//leftward (= 0), downward (= 1), rightward (= 2), and upward (= 3).
int dir[][2]={0,-1, 1,0, 0,1, -1,0};
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)&&n){
        //printf("!!! %d\n",n);
        x[0]=y[0]=0;
        x1=x2=0;
        y1=y2=0;
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            x[i]=x[a]+dir[b][0];
            y[i]=y[a]+dir[b][1];
            x1=min(x1,x[i]);
            x2=max(x2,x[i]);
            y1=min(y1,y[i]);
            y2=max(y2,y[i]);
        }
        int ans1=x2-x1+1, ans2=y2-y1+1;
        printf("%d %d\n",ans2,ans1);
    }
    return 0;
}
