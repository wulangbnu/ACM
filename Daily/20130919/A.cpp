#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<string>
using namespace std;
const int maxn=45;
const int maxm=50005;

int f[maxn][4];
int n;
int p[maxn],t[maxn];

int main() {
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)&&n) {
        memset(f,-1,sizeof(f));
        f[0][0]=0;
        for(int i=1; i<=n; i++)
            scanf("%d%d",&p[i],&t[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<4; j++) {
                if(f[i][j]==-1)continue;
                if(j<3) {
                    int tt=t[i]+abs(p[i]-p[i+1])*(j+1);
                    if(tt<=t[i+1]) {
                        if(f[i+1][j+1]==-1)f[i+1][j+1]=f[i][j]+abs(p[i]-p[i+1]);
                        else f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+abs(p[i]-p[i+1]));
                    }
                }
                int tt=t[i]+p[i]*(j+1)+p[i+1];
                if(tt<=t[i+1]) {
                    if(f[i+1][1]==-1)f[i+1][1]=f[i][j]+p[i]+p[i+1];
                    else f[i+1][1]=min(f[i+1][1],f[i][j]+p[i]+p[i+1]);
                }
            }
        int ret=-1;
        for(int i=1; i<=3; i++)
            if(f[n][i]!=-1) {
                int tt=f[n][i]+p[n];
                if(ret==-1)ret=tt;
                else ret=min(ret,tt);
            }
        if(ret==-1) {
            int idx=0;
            for(int i=1; i<=n; i++)
                for(int j=1; j<=3; j++)
                    if(f[i][j]!=-1)idx=i;
            printf("NG %d\n",idx+1);
        } else printf("OK %d\n",ret);
    }
    return 0;
}
