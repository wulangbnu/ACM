#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MP make_pair
using namespace std;
const int N=20000+10;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
typedef vector<pii> vp;
int n,a[N],b[N],x[N],y[N],cntx,cnty,my[2][N];
void doit(int x[],int a[],int &cnt){
    memcpy(a,x,sizeof(int)*n);
    sort(a,a+n);
    cnt=unique(a,a+n)-a;
    for(int i=0;i<n;i++) x[i]=lower_bound(a,a+cnt,x[i])-a;
}
void work(int x,int y,int add,vp &vs,int m[],int finish,bool left){
    vs.push_back(MP(x,m[x]));
    int pre=m[x];
    for(int i=x;i!=y&&pre!=finish;i+=add){
        int now=m[i];
        if(left&&now>=pre) continue;
        if(!left&&now<=pre) continue;
        vs.push_back(MP(i,pre));
        vs.push_back(MP(i,now));
        pre=now;
    }
}
void F(pii x,int adx,int ady){
    printf(" %d %d",a[x.first]+adx,b[x.second]+ady);
}
int main(){
    //freopen("in.cpp","r",stdin);
    int cas=0;
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
        doit(x,a,cntx);
        doit(y,b,cnty);
        for(int i=0;i<cntx;i++){
            my[0][i]=INF; my[1][i]=-INF;
        }
        for(int i=0;i<n;i++){
            my[0][x[i]]=min(my[0][x[i]],y[i]);
            my[1][x[i]]=max(my[1][x[i]],y[i]);
        }

        vp v[4];
        work(0,cntx-1,1,v[0],my[0],0,true);
        work(cntx-1,0,-1,v[1],my[0],0,true);
        work(0,cntx-1,1,v[2],my[1],cnty-1,false);
        work(cntx-1,0,-1,v[3],my[1],cnty-1,false);

        printf("Case %d:",++cas);
        F(v[0][0],0,0);
        for(int i=0;i<v[2].size();i++)    F(v[2][i],0,9);
        for(int i=v[3].size()-1;i>=0;i--) F(v[3][i],9,9);
        for(int i=0;i<v[1].size();i++)    F(v[1][i],9,0);
        for(int i=v[0].size()-1;i>0;i--)  F(v[0][i],0,0);
        puts("");
    }
    return 0;
}
