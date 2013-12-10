#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<time.h>
using namespace std;
const int maxn=4;


int a[1000][1000];
int c[100000];

int d[3]={-1,0,1};



int tot=0;

void dfs(int dep) {
    //printf("** %d\n",dep);
    if(dep==maxn*maxn) {
       // printf("*** %d\n",tot++);

        int cnt=0;
        for(int i=0; i<maxn; i++) {
            int ret=0;
            for(int j=0; j<maxn; j++)
                ret+=a[i][j];
            c[cnt++]=ret;
        }
        for(int j=0; j<maxn; j++) {
            int ret=0;
            for(int i=0; i<maxn; i++)
                ret+=a[i][j];
            c[cnt++]=ret;
        }
        sort(c,c+cnt);
        bool sign=0;
        for(int i=1; i<=cnt-1; i++)if(c[i]==c[i-1])sign=1;
        int sign2=0;
        for(int i=0;i<maxn;i++)
          for(int j=0;j<maxn;j++)
          if(a[i][j]==0)sign2++;
        //printf("**\n");
        if(!sign) {
            printf("**\n");
            for(int i=0; i<maxn; i++) {
                for(int j=0; j<maxn; j++)
                    printf("%d ",a[i][j]);
                printf("\n");
            }
        }
        return;
    }
    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++)
            if(a[i][j]==-1000) {
                /*a[i][j]=-1;
                dfs(dep+1);
                a[i][j]=-1000;

                a[i][j]=0;
                dfs(dep+1);
                a[i][j]=-1000;

                a[i][j]=1;
                dfs(dep+1);
                a[i][j]=-1000;*/
               random_shuffle(d,d+3);
               for(int k=0;k<3;k++)
                {
                    a[i][j]=d[k];
                    dfs(dep+1);
                }
                a[i][j]=-1000;
                return;
            }
}


int main() {
    srand(time(NULL));
    //freopen("in.cpp","r",stdin);
    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++)
            a[i][j]=-1000;


    a[1][1]=-1;
    a[1][2]=1;
    a[2][1]=0;
    a[2][2]=1;


    dfs(4);
    return 0;
}
