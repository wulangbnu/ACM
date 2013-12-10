#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=300+10;
char str[N][N];
int n,tag[N];
void dfs(int x,int v){
    if(tag[x]!=-1) return;
    tag[x]=v;
    for(int i=0;i<n;i++) if(str[x][i]=='1') dfs(i,1-v);
}
bool check(){
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i!=j&&str[i][j]=='1'&&tag[i]==tag[j]) return false;
    return true;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        memset(tag,-1,sizeof(tag));
        for(int i=0;i<n;i++) dfs(i,0);
        //for(int i=0;i<n;i++) printf("%d %d\n",i,tag[i]);
        if(check()) puts("Yes");
        else puts("No");
    }
    return 0;
}
