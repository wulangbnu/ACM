#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
const int N=1000000+10;
char str[N],str2[N];
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
            printf("%s",ss.c_str());
            puts("");
            i++;
        }
        //start tag
        else if(ss[0]=='<'){
            if(ss=="<html>") printf("Case #%d:\n",++cas);
            pt(x);
            x++;
            while(vs[i][vs[i].size()-1]!='>') printf("%s ",vs[i++].c_str());
            printf("%s",vs[i].c_str());
            if(vs[i].size()>=2&&vs[i][vs[i].size()-2]=='/') x--;
            puts("");
            i++;
        }
        //text
        else{
            pt(x);
            printf("%s",ss.c_str());
            while(vs[++i][0]!='<') printf(" %s",vs[i].c_str());
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
        int k=0;
        for(int i=0;str[i];i++){
            if(str[i]=='<') str2[k++]=' ';
            str2[k++]=str[i];
            if(str[i]=='>') str2[k++]=' ';
        }
        str2[k]=0;
        istringstream in(str2);
        string ss;
        while(in>>ss) vs.push_back(ss);
    }
    solve();
    return 0;
}
