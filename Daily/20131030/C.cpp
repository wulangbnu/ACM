#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N=500000+10;
struct Node{
    Node *pre,*next;
    int v;
}node[N],*pool,*root,*c[N];
int cnt,n,m;
void init(){
    pool=node;
    root=++pool;
    root->v=-1;
    root->next=0;
    cnt=1;
    c[cnt]=root;
}
void Learn(int id,int v){
    Node *cur=c[id];
    cur->next=++pool;
    pool->pre=cur;
    pool->next=0;
    pool->v=v;
    c[id]=pool;
}
void Rollback(int id){
    Node *cur=c[id]->pre;
    ++pool;
    pool->next=c[id];
    pool->pre=cur->pre;
    pool->v=cur->v;
    c[id]=pool;
}
void Relearn(int id){
    Node *cur=c[id]->next;
    ++pool;
    pool->next=cur->next;
    pool->pre=c[id];
    pool->v=cur->v;
    c[id]=pool;
}
void Clone(int id){
    Node *cur=c[id];
    ++pool;
    pool->next=cur->next;
    pool->pre=cur->pre;
    pool->v=cur->v;
    c[++cnt]=pool;
}
void Check(int id){
    int v=c[id]->v;
    if(v==-1) puts("basic");
    else printf("%d\n",v);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&m)+1){
       /*
        learn ci pi. Teach clone ci program pi (1 ≤ pi ≤ m).
        rollback ci. Cancel the last learned program for clone ci.
        relearn ci. Apply ‘re-learn’ function to clone ci.
        clone ci. Clone the clone ci.
        check ci. Display the last program clone ci has learned and knows at the moment.
        */
        init();
        char str[20];
        string ss;
        int id,v;
        for(int re=0;re<n;re++){
            scanf("%s",str);
            ss=str;
            //puts(str);
            if(ss=="learn"){
                scanf("%d%d",&id,&v);
                Learn(id,v);
            }else if(ss=="rollback"){
                scanf("%d",&id);
                Rollback(id);
            }else if(ss=="relearn"){
                scanf("%d",&id);
                Relearn(id);
            }else if(ss=="clone"){
                scanf("%d",&id);
                Clone(id);
            }else if(ss=="check"){
                scanf("%d",&id);
                Check(id);
            }
        }
    }
    return 0;
}
