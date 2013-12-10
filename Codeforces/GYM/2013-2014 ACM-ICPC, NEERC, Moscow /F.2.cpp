#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=24*60+5;
struct P {
    int x,y;
} p[maxn];
int n;
int f[maxn],c[maxn][maxn],d[maxn][maxn],sum[maxn];
char str[5];

int doit(int x,int y) {
    if(x>y) return 0;
    int ret=0;
    int start=p[x].x,tot,cnt;
    if(p[x].y==1){
        ret+=28;
        tot=44-28;
        cnt=1;
    }else{
        ret+=26;
        tot=44-26;
        cnt=0;
    }

    for(int i=x+1; i<=y; i++) {
        //subway
        if(p[i].y==1) {
            if(p[i].x-start<=90&&cnt==0){
                ret+=tot;
                cnt++;
                tot=0;
            }else{
                ret+=sum[y]-sum[i-1];
                break;
            }
        }else{
            if(p[i].x-start<=90){
                ret+=tot;
                tot=0;
            }else{
                ret+=sum[y]-sum[i-1];
                break;
            }
        }
    }
    return ret;
}
int solve_1() {
    int ret=0;
    int start=-maxn,tot,cnt=0;
    for(int i=1; i<=n; i++) {
        //subway
        if(p[i].y==1) {
            if(p[i].x-start<=90&&cnt==0){
                ret+=tot;
                cnt++;
                tot=0;
            }else{
                ret+=28;
                cnt=1;
                start=p[i].x;
                tot=44-28;
            }
        }else{
            if(p[i].x-start<=90){
                ret+=tot;
                tot=0;
            }else{
               ret+=26;
               cnt=0;
               start=p[i].x;
               tot=44-26;
            }
        }
    }
    return ret;
}

void pd(int &ret,int val) {
    if(val==-1)return;
    if(ret==-1)ret=val;
    ret=min(ret,val);
}

int get(int x) {
    if(x)return 28;
    else return 26;
}
int solve_2() {

    for(int i=1; i<=n; i++) {
        sum[i]=sum[i-1];
        if(p[i].y)sum[i]+=28;
        else sum[i]+=26;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            c[i][j]=doit(i,j);

    //printf("** %d\n",c[1][n]);

    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            d[i][j]=d[i][j-1]+p[j].y;
    memset(f,-1,sizeof(f));
    f[0]=0;

    int ret=sum[n];
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if(j==0) {
                pd(f[i],sum[i]);
            } else {
                if(p[i].x-p[j].x>90||d[j][i]>1) {
                    pd(f[i],f[j]+c[j][i-1]+get(p[i].y)-get(p[j].y));
                }
            }
        }
       // if(i==4)printf("** %d\n",f[i]);
     //  printf("%d: %d %d %d %d\n",i,f[i],get(p[i].y),c[i][n],f[i]-get(p[i].y)+c[i][n]);
        pd(ret,f[i]-get(p[i].y)+c[i][n]);
    }
    //for(int i=1;i<=n;i++)printf("%d ",f[i]);
   // printf("\n");
    return ret;
}

int main() {
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        for(int i=1; i<=n; i++) {
            int x,y;
            scanf("%d:%d",&x,&y);
            p[i].x=x*60+y;
            scanf("%s",str);
            if(str[0]=='U')p[i].y=1;
            else p[i].y=0;
        }
        printf("%d %d\n",solve_1(),solve_2());
    }
    return 0;
}
