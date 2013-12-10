#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<char,char> mp;
void init(){
    mp['b']='d'; mp['d']='b';
    mp['p']='q'; mp['q']='p';
    mp['i']='i';
    mp['o']='o';
    mp['v']='v';
    mp['w']='w';
    mp['x']='x';
}
int main(){
    //freopen("in.cpp","r",stdin);
    init();
    string ss;
    while(cin>>ss&&ss!="#"){
        string ans="";
        int f=0;
        for(int i=ss.size()-1;i>=0;i--){
            if(!mp.count(ss[i])) f=1;
            else ans+=mp[ss[i]];
        }
        if(f) puts("INVALID");
        else cout<<ans<<endl;
    }
    return 0;
}
