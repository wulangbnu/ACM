#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=50000+10;
typedef __int64  ll;
int n,m,len[N];
string ss[N];
ll a[N];
struct Node{
    Node *next[26];
    void init(){
        memset(next,0,sizeof(next));
    }
}node[500000],*root[N],*pool;
void init(){
    pool=node;
    for(int i=0;i<n;i++){
        root[i]=++pool;
        pool->init();
        len[i]=0;
        a[i]=0;
    }
    a[n]=0;
}
void sweep(){
    for(int i=0;i<n;i++) ss[i].clear();
}
int insert(int id){
    Node *Root=root[id];
    int ret=0;
    for(int i=len[id]-1;i>=0;i--){
        int x=ss[id][i]-'a';
        if(!Root->next[x]){
            Root->next[x]=++pool;
            pool->init();
            ret++;
        }
        Root=Root->next[x];
    }
    return ret;
}
inline int lowbit(int i){
    return i&(-i);
}
void add(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i))
    a[i]+=val;
}
ll sum(int x){
    ll ret=0;
    for(int i=x;i>0;i-=lowbit(i)) ret+=a[i];
    return ret;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,x,y,id;
    char str[5];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        printf("Case %d:\n",cas++);
        while(m--){
            scanf("%s",str);
            if(str[0]=='S'){
                scanf("%d%d",&x,&y);
                printf("%I64d\n",sum(y+1)-sum(x));
            }
            else{
                scanf("%d%s",&id,str);
                ss[id]+=str[0];
                len[id]++;
                x=insert(id);
                add(id+1,x);
            }
        }
        sweep();
    }
    return 0;
}
