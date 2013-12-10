#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1000000+10;
char str[N],ss[505];
struct node
{
   node *fail,*next[26];
   int count;
   void init(){
        fail=NULL;
        count=0;
        memset(next,NULL,sizeof(next));
   }
}npool[250000+10],*ntop,*id[505];
node* insert(char *str,node *root)
{
    node *cur=root;
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(cur->next[x]==NULL){
            cur->next[x]=ntop++;
            cur->next[x]->init();
        }
        cur=cur->next[x];
    }
    return cur;
}
queue<node*> q;
void build_AC(node *root)
{
    root->fail=NULL;
    q.push(root);
    while(!q.empty()){
        node *cur=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(cur->next[i]==NULL) continue;
            if(cur==root) cur->next[i]->fail=root;
            else{
                node *tmp=cur->fail;
                while(tmp){
                    if(tmp->next[i]!=NULL){
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
void query(char *str,node *root)
{
    node *cur=root;
    for(int i=0;str[i];i++){
        int index=str[i]-'a';
        while(cur->next[index]==NULL&&cur!=root) cur=cur->fail;
        cur=cur->next[index];
        if(!cur) cur=root;
        node *tmp=cur;
        while(tmp!=root){
            (tmp->count)++;
            tmp=tmp->fail;
        }
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        ntop=npool;
        node *root=ntop++;
        root->init();

        scanf("%d",&n);
        scanf("%s",str);
        for(i=0;i<n;i++){
            scanf("%s",ss);
            id[i]=insert(ss,root);
        }
        build_AC(root);
        query(str,root);
        for(i=0;i<n;i++)
        printf("%d\n",id[i]->count);
    }
    return 0;
}
