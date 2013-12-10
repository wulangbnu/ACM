#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N=50+10;
char str[N][N],mask[N][N],mask2[N][N];
int n;
string ss[4];
struct Node{
    char v;
    Node *next[26];
    void init(){
        v=0;
        memset(next,0,sizeof(next));
    }
}node[2000+10],*pool,*Root;
void doit(string &s){
    s="";
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        if(mask[i][j]=='*'&&str[i][j]!='.') s+=str[i][j];
    }
    //cout<<s<<endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        mask2[j][n-1-i]=mask[i][j];
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        mask[i][j]=mask2[i][j];
    }
}
void init(){
    Root=pool=node;
    pool++;
    Root->init();
}
void insert(char str[],Node *root){
    for(int i,j=0;str[j];j++){
        i=str[j]-'a';
        if(!root->next[i]){
            root->next[i]=pool;
            pool->init();
            pool++;
        }
        root=root->next[i];
    }
    root->v=1;
}
string sss;
bool dfs(int pos,int len,Node *root){
    int x=sss[pos]-'a';
    if(pos==len-1){
        if(root->next[x]&&root->next[x]->v) return true;
        else return false;
    }
    if(!root->next[x]) return false;
    if(root->next[x]->v&&dfs(pos+1,len,Root)) return true;
    return dfs(pos+1,len,root->next[x]);
}
int main(){
    freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        for(int i=0;i<n;i++) scanf("%s",mask[i]);
        for(int i=0;i<4;i++) doit(ss[i]);

        init();
        int m;
        scanf("%d",&m);
        while(m--){
            scanf("%s",str[0]);
            insert(str[0],Root);
        }

        int len=0;
        for(int i=0;i<4;i++) len+=ss[i].size();
        string ans="";
        for(int i=0;i<4;i++){
            sss="";
            for(int j=0;j<4;j++) sss+=ss[(i+j)%4];
            if(dfs(0,len,Root)&&(ans.size()==0||sss<ans)) ans=sss;
        }
        printf("Case #%d: ",cas++);
        if(ans.size()) puts(ans.c_str());
        else puts("FAIL TO DECRYPT");
    }
    return 0;
}
