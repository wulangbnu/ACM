#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct ErasingCharacters{
    string simulate(string s){
        int x=-1;
        for(int i=0;i+1<s.size();i++){
            if(s[i]==s[i+1]){x=i; break;}
        }
        if(x==-1) return s;
        string ss="";
        for(int i=0;i<x;i++) ss+=s[i];
        for(int i=x+2;i<s.size();i++) ss+=s[i];
        return simulate(ss);
    }
};
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif



    return 0;
}
