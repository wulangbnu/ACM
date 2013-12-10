#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int N=300000+10;
int dp[20000+10];
int v[20000+10];
struct Node{
    Node *fail,*next[26];
    int id;
    void init(){
        fail=0;
        id=0;
        memset(next,0,sizeof(next));
    }
}node[N],*pool,*root;
queue<Node*>q;
void insert(char str[],int id){
    Node *cur=root;
    for(int i=0;str[i];i++){
        int index=str[i]-'a';
        if(!cur->next[index]){
            cur->next[index]=pool;
            pool->init();
            pool++;
        }
        cur=cur->next[index];
    }
    cur->id=id;
}
void build_AC(){
    root->fail=0;
    q.push(root);
    while(!q.empty()){
        Node *cur=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(!cur->next[i]) continue;
            if(cur==root) cur->next[i]->fail=root;
            else{
                Node *tmp=cur->fail;
                while(tmp){
                    if(tmp->next[i]){
                        cur->next[i]->fail=tmp->next[i];
                        break;
                    }
                    tmp=tmp->fail;
                }
                if(!tmp) cur->next[i]->fail=root;
            }
            q.push(cur->next[i]);
        }
    }
}
int query(char str[],int id){
    int res=0;
    Node *cur=root;
    for(int i=0;str[i];i++){
        int index=str[i]-'a';
        while(!cur->next[index]&&cur!=root) cur=cur->fail;
        cur=cur->next[index];
        if(!cur) cur=root;
        Node *tmp=cur;
        while(tmp!=root){
            if((tmp->id)<id) res=max(res,dp[tmp->id]);
            tmp=tmp->fail;
        }
    }
    return res;
}
int n;
char str[N+10];
void init(){
    root=pool=node;
    root->init();
    pool++;
}
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&n);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%s%d",str,&v[i]);
            insert(str,i);
            dp[i]=0;
        }
        build_AC();
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
