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
const int T=10007;
int d[N][N];
bool solve(){

    int s=n;
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<=n;i++) d[i][i]=0;

    for(int i=0;i<n;i++){
        if(tag[i]){
            d[s][i]=T-1;
            d[i][s]=-1;
        }
        else{
            d[s][i]=-1;
            d[i][s]=T-1;
        }
    }
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        if(tag[i]==tag[j]) continue;
        if(str[i][j]=='0'){
            int x=i, y=j;
            if(tag[x]==0) swap(x,y);
            d[y][x]=T-1;
        }
        else{
            int x=i, y=j;
            if(tag[x]==0) swap(x,y);
            d[x][y]=-T;
        }
    }

    for(int k=0;k<=n;k++)
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }

//    for(int i=0;i<n;i++){
//        if(tag[i]&&d[s][i]<1) return false;
//        if(!tag[i]&&d[s][i]<-(T-1)) return false;
//    }

    for(int k=0;k<=n;k++)
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    if(d[i][k]+d[k][j]<d[i][j]) return false;

    return true;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        memset(tag,-1,sizeof(tag));
        for(int i=0;i<n;i++) dfs(i,0);
        //for(int i=0;i<n;i++) printf("%d %d\n",i,tag[i]);
        if(!check()||!solve()) puts("No");
        else puts("Yes");
    }
    return 0;
}
