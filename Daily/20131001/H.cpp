#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=1005;

int n;
char s[maxn][maxn],t[maxn][maxn],ts[maxn][maxn];

void rotate() {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ts[i][j]=s[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            s[j][n-1-i]=ts[i][j];
}

int main() {
   // freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)&&n) {
        for(int i=0; i<n; i++)scanf("%s",s[i]);
        for(int i=0; i<n; i++)scanf("%s",t[i]);
        for(int i=0; i<4; i++) {
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    if(s[j][k]=='O')printf("%c",t[j][k]);
            rotate();
        }
        printf("\n");
    }
    return 0;
}
