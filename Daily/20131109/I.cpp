#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
#include <queue>
using namespace std;
typedef long long ll;
const int N=5000+10;
const int M=N/64+10;
vector<int> adj[N];
int  n,m,out[N];
bool tag[N];
struct Set{
    ll a[M];
    void init(){
        memset(a,0,sizeof(a));
    }
    //start from 0
    void set(int pos,int val){
        if(val==1) a[pos>>6]|=1ll<<(pos&63);
        else a[pos>>6]&=1ll<<(pos&((1<<6)-1));
    }
    void Union(const Set &set){
        for(int i=0;i<M;i++) a[i]|=set.a[i];
    }
    int count(){
        int cnt=0;
        for(int i=0;i<M;i++)
        for(ll j=a[i];j>0;j&=j-1)
        cnt++;
        return cnt;
    }
}st[N];
void init(){
    for(int i=1;i<=n;i++){
        adj[i].clear();
        st[i].init();
    }
    memset(tag,false,sizeof(tag));
    memset(out,0,sizeof(out));
}
bool getint(int &x){
    x=0;
    char ch=0;
    while(!isdigit(ch)){
        ch=getchar();
        if(ch=='\n') return false;
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    if(ch=='\n') return false;
    return true;
}
void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(out[i]==0) q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        st[x].set(x-1,1);
        for(int i=0;i<adj[x].size();i++){
            int y=adj[x][i];
            st[y].Union(st[x]);
            if(--out[y]==0) q.push(y);
        }
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)==2){
        init();
        while(m--){
            int i;
            scanf("%d ",&i);
            tag[i]=true;
        }
        for(int r=0;r<n;r++){
            int x,y;
            bool flag=getint(x);
            while(flag){
                flag=getint(y);
                out[x]++;
                adj[y].push_back(x);
            }
        }
        bfs();
        int tmp=0,x;
        for(int i=1;i<=n;i++){
            if(!tag[i]) continue;
            int cnt=st[i].count();
            //printf("~~ %d\n",cnt);
            if(cnt>tmp){
                tmp=cnt;
                x=i;
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
