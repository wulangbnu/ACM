#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=500+10;
bool g[N][N];
int get[N];
int a,b,n,v[N];
string s1[N],s2[N];
void add_edge(){
    memset(g,false,sizeof(g));
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        if(s1[i]==s2[j]||s2[i]==s1[j]) g[i][j]=g[j][i]=true;
    }
}
void dfs(int x,int val,int cnt){
    if(get[x]) return;
    get[x]=cnt;
    v[x]=val;
    for(int i=0;i<n;i++)
    if(g[x][i]) dfs(i,1-val,cnt);
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

        memset(get,0,sizeof(get));

        int tot=0,cnt=0;
        for(int i=0;i<n;i++){
            if(get[i]) continue;
            dfs(i,0,++cnt);
            int ans[2]={0};
            for(int j=0;j<n;j++)
            if(get[j]==cnt) ans[v[j]]++;
            tot+=max(ans[0],ans[1]);
        }
        printf("%d\n",tot);
    }
    return 0;
}
