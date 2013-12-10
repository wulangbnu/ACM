#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
const int N=300;
char str[N];
int next[N],n;
bool tag[N];
void doit(){
    stack<int> q;
    for(int i=0;i<n;i++){
        if(str[i]=='(') q.push(i);
        else if(str[i]==')'){
            next[q.top()]=i;
            q.pop();
        }
    }
}
void work(int x){
    int i;
    for(i=x-1;i>=0;i--){
        if(str[i]==' '||tag[i]) continue;
        else{
            if(str[i]=='+'||str[i]=='(')  tag[x]=tag[next[x]]=true;
            break;
        }
    }
    if(i<0) tag[x]=tag[next[x]]=true;
    if(tag[x]) return;
    for(i=x+1;i<next[x];i++){
        if(str[i]==' ') continue;
        if(str[i]=='+'||str[i]=='-') break;
    }
    if(i==next[x]) tag[x]=tag[next[x]]=true;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    gets(str);
    while(T--){
        gets(str);
        n=strlen(str);
        doit();

        memset(tag,false,sizeof(tag));
        for(int i=0;i<n;i++)
        if(str[i]=='(') work(i);

        for(int i=0;i<n;i++){
            if(str[i]==' '||tag[i]) continue;
            printf("%c",str[i]);
        }
        puts("");
    }
    return 0;
}
