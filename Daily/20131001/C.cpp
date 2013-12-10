#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=1000000+10;
int pre[N],pos[N],n,m;
int a[N],b[N];
struct Query{
    int x,y,id,ans;
    bool operator <(const Query &tt )const{
        return y<tt.y;
    }
}q[N];
bool cmp(Query q1,Query q2){
    return q1.id<q2.id;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)&&(n+m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++){
            scanf("%d%d",&q[i].x,&q[i].y);
            q[i].id=i;
        }
        sort(q,q+m);

        int cnt=0;
        for(int i=1;i<=n;i++) b[cnt++]=a[i];
        sort(b,b+cnt);
        cnt=unique(b,b+cnt)-b;
        for(int i=1;i<=n;i++) a[i]=lower_bound(b,b+cnt,a[i])-b;

        memset(pre,0,sizeof(pre));
        memset(pos,0,sizeof(pos));
        for(int i=1;i<=n;i++){
            pre[i]=pos[a[i]];
            pos[a[i]]=i;
        }
        int k=0;
        for(int x=0,y=1;y<=n;y++){
            x=max(x,pre[y]);
            //printf("~~ %d %d\n",x,y);
            while(k<m&&q[k].y==y){
                if(q[k].x<=x) q[k].ans=b[a[x]];
                else q[k].ans=-1;
                k++;
            }
        }
        sort(q,q+m,cmp);
        for(int i=0;i<m;i++){
            if(q[i].ans==-1) puts("OK");
            else printf("%d\n",q[i].ans);
        }
        puts("");
    }
    return 0;
}
