#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=500+10;
int a,b,n,v[N];
string s1[N],s2[N];
bool g[N][N],tag[N];
int my[N];
void add_edge(){
    memset(g,false,sizeof(g));
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        if(s1[i]==s2[j]||s2[i]==s1[j]) g[i][j]=g[j][i]=true;
    }
}
bool dfs(int x){
    for(int y=0;y<n;y++){
        if(!g[x][y]||tag[y]) continue;
        tag[y]=true;
        if(my[y]==-1||dfs(my[y])){
            my[y]=x;
            return true;
        }
    }
    return false;
}
int hk(){
    int ret=0;
    memset(my,-1,sizeof(my));
    for(int i=0;i<n;i++){
        memset(tag,false,sizeof(tag));
        if(dfs(i)) ret++;
    }
    return ret;
}
int main(){
    freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&n);
        char str[20];
        for(int i=0;i<n;i++){
            scanf("%s",str); s1[i]=str;
            scanf("%s",str); s2[i]=str;
        }
        add_edge();
        printf("%d\n",n-hk()/2);
    }
    return 0;
}
