#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
const int N=1024*20+10;
char str[N];
vector<string> vs;
int cas;
void pt(int x){
    for(int i=0;i<x;i++) printf(" ");
}
void solve(){
    int x=0,n=vs.size();
    for(int i=0;i<n;){
        string ss=vs[i];
        //endtag
        if(ss[0]=='<'&&ss.size()>1&&ss[1]=='/'){
            x--;
            pt(x);
            cout<<ss<<endl;
            i++;
        }
        //start tag
        else if(ss[0]=='<'){
            if(ss=="<html>") printf("Case #%d:\n",++cas);
            pt(x);
            x++;
            cout<<ss<<endl;
            if(ss.size()>=2&&ss[ss.size()-2]=='/') x--;
            i++;
        }
        //text
        else{
            pt(x);
            cout<<ss;
            while(vs[++i][0]!='<') cout<<" "<<vs[i];
            puts("");
        }
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    gets(str);
    while(gets(str)){
        int len=strlen(str);
        string ss="";
        for(int i=0;i<len;i++){
            if(str[i]=='<'){
                if(ss!="") vs.push_back(ss);
                ss="";
                while(true){
                    ss+=str[i];
                    if(str[i]=='>') break;
                    i++;
                }
                if(ss!="") vs.push_back(ss);
                ss="";
            }else if(str[i]==' '||str[i]=='\t'||str[i]=='\r'){
                if(ss!="") vs.push_back(ss);
                ss="";
            }else ss+=str[i];
        }
        if(ss!="") vs.push_back(ss);
    }
    //for(int i=0;i<vs.size();i++) cout<<vs[i]<<endl;
    solve();
    return 0;
}
