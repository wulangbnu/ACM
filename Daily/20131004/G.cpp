#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=10;

int d[maxn][maxn];
int f[1<<maxn][10],g[5][1<<maxn];
int s,n,p;

void init() {
    memset(f,-1,sizeof(f));
    memset(g,-1,sizeof(g));
    f[1][0]=0;
    memset(d,-1,sizeof(d));
    for(int i=0; i<maxn; i++)d[i][i]=0;
}

void pd(int &ret,int val) {
    if(val==-1)return;
    if(ret==-1)ret=val;
    ret=min(ret,val);
}

char str[5];
int main() {
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&s)&&s) {
        init();
        scanf("%d%d",&n,&p);
        for(int i=0; i<p; i++) {
            scanf("%s",str);
            int u=str[0]-'A';
            int v=str[1]-'A';
            d[u][v]=d[v][u]=1;
        }
        for(int k=0; k<s; k++)
            for(int i=0; i<s; i++)
                for(int j=0; j<s; j++)
                    if(d[i][k]!=-1&&d[k][j]!=-1)
                        pd(d[i][j],d[i][k]+d[k][j]);

        for(int i=0; i<(1<<s); i++)
            for(int j=0; j<s; j++) {
                if(f[i][j]==-1)continue;
                for(int k=0; k<s; k++) {
                    if(i&(1<<k))continue;
                    pd(f[i|(1<<k)][k],f[i][j]+d[j][k]);
                }
            }

        // for(int i=0;i<(1<<s);i++)
        // printf("%d :%d\n",i,f[i]);

        //printf("%d %d %d\n",s,n,p);
        for(int i=0;i<(1<<s);i++)
          for(int j=0;j<s;j++)
           pd(g[1][i],f[i][j]);

        // printf("**\n");
        for(int i=2; i<=n; i++)
            for(int j=0; j<(1<<s); j++)
                if(j&1) {
                    for(int k=j;; k=((k-1)&j)) {
                        //printf("** %d\n",k);
                        int tk=(k|1);
                        int l=((j^k)|1);
                        pd(g[i][j],max(g[i-1][l],g[1][tk]));
                        if(k==0)break;
                    }
                }
        printf("%d\n",g[n][(1<<s)-1]);
    }
    return 0;
}

