#include<cstdio>
#include<cstring>
#include<algorithm>
using  namespace std;
const int N=30+10;
int a[N][N],b[N];
int n,m,k,p;
bool check(){
    int i,j,r;
    for(i=0;i<n;i++){
        bool flag=false;
        for(j=0;j<k;j++){
            if(a[i][j]>0){
                for(r=0;r<p;r++)
                if(a[i][j]==b[r]) flag=true;
            }
            else{
                for(r=0;r<p;r++)
                if(-a[i][j]==b[r]) break;

                if(r>=p) flag=true;
            }
        }
        if(!flag) return false;
    }
    return true;
}
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=1,i,j;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)
        for(j=0;j<k;j++){
            scanf("%d",&a[i][j]);
        }
        scanf("%d",&p);
        for(i=0;i<p;i++) scanf("%d",&b[i]);
        if(check()) puts("Yes");
        else puts("No");
    }
    return 0;
}
