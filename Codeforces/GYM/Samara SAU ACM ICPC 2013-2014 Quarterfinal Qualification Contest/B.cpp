#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=1000000+10;
struct Node{
    int v;
    Node *next[26];
    void init(){
        v=0;
        memset(next,0,sizeof(next));
    }
}node[N],*root,*pool;
char str[N];
int next[26];
void init(){
    pool=node;
    root=++pool;
    root->init();
}
void insert(char str[],Node *root){
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(!root->next[x]){
            root->next[x]=++pool;
            pool->init();
        }
        root=root->next[x];
    }
    root->v++;
}
int query(char str[],Node *root){
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(!root->next[x]) return 0;
        root=root->next[x];
    }
    return root->v;
}
void doit(char str[]){
    memset(next,-1,sizeof(next));
    for(int tot=0,i=0;str[i];i++){
        int x=str[i]-'a';
        if(next[x]==-1) next[x]=tot++;
        str[i]=next[x]+'a';
    }
}
int main(){
    //freopen("in.cpp","r",stdin);

    int n;
    while(scanf("%d",&n)+1){
        init();
        ll ans=0;
        while(n--){
            scanf("%s",str);
            doit(str);
            //puts(str);
            ans+=query(str,root);
            insert(str,root);
        }
        cout<<ans<<endl;
    }
    return 0;
}
