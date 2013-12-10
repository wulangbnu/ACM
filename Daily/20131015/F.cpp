#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;
const int N=2000+10;
char str[N];
int main(){
    //freopen("F.in.cpp","r",stdin);
    while(gets(str)&&strcmp(str,"*")){
        istringstream in(str);
        vector<string> st;
        string ss;
        while(in>>ss) st.push_back(ss);
        char ans='Y';
        for(int i=0;i<st.size();i++){
            if(toupper(st[0][0])!=toupper(st[i][0])) ans='N';
        }
        printf("%c\n",ans);
    }
    return 0;
}
