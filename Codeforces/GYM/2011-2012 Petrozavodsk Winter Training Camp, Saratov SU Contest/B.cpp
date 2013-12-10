#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
typedef long long ll;
const int N=100000+10;
const ll INF=1000000000000ll;
char str[N];
struct Node{
    ll cnt[26],next[26];
    vector<int> adj;
    ll v,mul[26];
    int depth,pos;
    void output(){
        cout<<depth<<" "<<v<<" "<<pos<<endl;
        for(int i=0;i<26;i++)
        if(cnt[i]+next[i]){ printf("%c   ",i+'a'); cout<<cnt[i]+next[i]<<endl; }
    }
}p[N];
int n,pre[N];
ll cnt[26],m;
void doit(){
    n=1;
    int v=0,depth=0;
    for(int i=0;str[i];i++){
        if(isdigit(str[i])) v=v*10+str[i]-'0';
        else if(str[i]=='('){
            p[n].v=v;
            p[n].depth=depth++;
            v=0;
            p[++n].pos=i+1;
        }else if(str[i]==')'){
            p[n].depth=depth--;
            p[++n].pos=i+1;
        }else p[n].cnt[str[i]-'a']++;
    }

    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++){
        int depth=p[i].depth;
        if(depth-1>=0&&pre[depth-1]!=-1) p[pre[depth-1]].adj.push_back(i);
        pre[depth]=i;
    }
}
void inline add(int x,ll val){
    if(cnt[x]==-1) return;
    cnt[x]+=val;
    if(cnt[x]>INF) cnt[x]=-1;
}
ll inline F(ll x,ll y){
    if(x==0) return 0;
    return min(INF/x+1,y)*x;
}
void dfs(int x){
    if(pre[x]!=-1) return;
    pre[x]=1;
    for(int i=0;i<p[x].adj.size();i++){
        int y=p[x].adj[i];
        dfs(y);
        for(int i=0;i<26;i++){
            p[x].next[i]+=F(p[y].next[i],p[y].v)+p[y].cnt[i];
        }
    }
}
void work(int x){

    if(cnt[0]==m) return;

    if(cnt[0]+p[x].cnt[0]>=m){
        for(int i=p[x].pos;;i++){
            add(str[i]-'a',1);
            if(cnt[0]==m) return;
        }
    }

    for(int i=0;i<26;i++)
    add(i,p[x].cnt[i]);

    ll low=0,high=p[x].v;
    if(p[x].v!=0){
        ll val=p[x].next[0];
        while(low<high){
            ll mid=(low+high+1)>>1;
            if(cnt[0]+F(val,mid)<m) low=mid;
            else high=mid-1;
        }
        for(int i=0;i<26;i++)
        add(i,F(p[x].next[i],low));
    }

    if(low!=p[x].v){
        for(int i=0;i<p[x].adj.size();i++){
            int y=p[x].adj[i];
            work(y);
        }
    }
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    #ifndef wulang
        freopen("az.in","r",stdin);
        freopen("az.out","w",stdout);
    #endif

    scanf("%s",str);
    cin>>m;
    doit();
    //puts(str);

    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++) dfs(i);
    //for(int i=1;i<=n;i++) p[i].output();

    for(int i=1;i<=n;i++){
        if(p[i].depth!=0) continue;
        if(cnt[0]+p[i].cnt[0]+F(p[i].next[0],p[i].v)>=m){
            work(i); break;
        }
        for(int k=0;k<26;k++) add(k,p[i].cnt[k]+F(p[i].next[k],p[i].v));
    }

    for(int k=0;k<26;k++)
    if(cnt[k]){
        printf("%c ",k+'a'); cout<<cnt[k]<<endl;
    }

    return 0;
}
/**

a8(6(2(aa6(a6(b3(8(4(ab10(b3(bb)a)b)b)a)bb)b)a)ba)a)
2246

ans:
a 2246
b 14688


4(4(a5(a10(6(b3(10(7(8(1(6(b9(6(8(4(b6(2(7(a3(7(7(6(9(3(a5(5(a10(9(4(5(8(8(a9(a6(b1(a8(b1(a7(1(8(a10(ab8(1(a5(10(1(8(a5(1(b4(6(a1(1(2(10(1(a6(1(7(a1(5(10(6(b6(6(3(6(b3(10(a7(a6(b6(bb2(10(4(b7(8(10(2(3(a7(5(bb6(9(10(6(8(8(8(a2(b10(bb6(1(b7(b1(9(9(b8(b8(7(ab)b)a)ab)b)ba)b)a)b)b)b)b)ab)ab)b)b)bb)b)a)a)b)aa)bb)b)a)b)ba)ab)b)a)ab)a)ab)a)b)a)b)b)aa)b)b)b)a)ba)bb)a)b)a)b)a)b)b)b)ab)a)bb)b)b)aa)aa)a)a)b)b)a)a)a)a)a)a)ab)b)b)ab)b)a)a)a)b)bb)b)a)b)a)a)aa)aa)b)b)bb)a)b)b)ba)a)a)a)a)aa)b)
98924

ans:
a 98924
b 113019


abca44(bc4(baba5(bvcbsba)v)39(a4(abbc)4(bava)6(njpam)ahb)a)baanab23(aava)
100

a8(6(2(aa6(a6(b3(8(4(ab10(b3(bb)a)b)b)a)bb)b)a)ba)a)
2246

abca44(bc4(baba5(bvcbsba)v)39(a4(abbc)4(bava)6(njpam)ahb)a)baanab23(aava)
50

ab2(b3(az))z
100

**/
