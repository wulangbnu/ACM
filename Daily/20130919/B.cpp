#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
const int N=1000+10;
map<string,int> mp;
set<int> st[N];
set<int>:: iterator it;
vector<int> adj[N],ve[N];
int n,cnt;
char str[2000+10];
string name[N],ss;
bool type[N];
int in[N];
void init(){
    mp.clear();
    for(int i=0;i<N;i++){
        st[i].clear();
        adj[i].clear();
        ve[i].clear();
    }
    cnt=0;
    memset(type,0,sizeof(type));
    memset(in,0,sizeof(in));
}
void add_edge(){
    for(int i=0;i<n;i++){
        int id=mp[name[i]];
        for(int j=0;j<ve[id].size();j++){
            int x=ve[id][j];
            if(type[x]){
                adj[x].push_back(id);
                in[id]++;
            }else{
                st[id].insert(x);
            }
        }
    }
}
int q[N];
void doit(){
    int l=0,r=0;
    for(int i=0;i<n;i++){
        int id=mp[name[i]];
        if(in[id]==0) q[r++]=id;
    }
    while(l!=r){
        int x=q[l++];
        for(int i=0;i<adj[x].size();i++){
            int y=adj[x][i];
            st[y].insert(st[x].begin(),st[x].end());
            if(--in[y]==0) q[r++]=y;
        }
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)&&n){
        init();
        getchar();
        for(int i=0;i<n;i++){

            gets(str);
            for(int j=0;str[j];j++)
            if(str[j]==':'||str[j]==','||str[j]=='.') str[j]=' ';

            istringstream in(str);

            //team
            in>>ss;
            name[i]=ss;
            if(mp.count(ss)==0) mp[ss]=cnt++;
            int id=mp[ss];
            type[id]=true;

            string ss;
            while(in>>ss){
                if(mp.count(ss)==0) mp[ss]=cnt++;
                ve[id].push_back(mp[ss]);
            }
        }
        add_edge();
        doit();
        printf("%d\n",(int)st[0].size());
    }
    return 0;
}
