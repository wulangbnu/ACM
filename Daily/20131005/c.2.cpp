#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200+10;
int a[N][N];
int r[N],c[N];
int n=6;
bool dfs(int x,int y){
    if(y==n){
        x++; y=0;
    }
    if(x==n-1&&y==n-1){
        for(int i=0;i<n;i++) r[i]=c[i]=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            r[i]+=a[i][j];
            c[j]+=a[i][j];
        }
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        if(r[i]==r[j]||c[i]==c[j]) return false;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(r[i]==c[j]) return false;
        return true;
    }
    int xx[]={-1,1,0};
    random_shuffle(xx,xx+3);
    for(int i=0;i<3;i++){
        a[x][y]=xx[i];
        if(dfs(x,y+1)) return true;
    }
    return false;
}
int main(){
    if(dfs(0,0)){
        for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<n;j++)
        printf("%2d ",a[i][j]);
    }
    return 0;
}

