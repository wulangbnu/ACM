#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int N=100;
char str[N];
map<char,int> icp,isp;
char p[N];
bool q[N];
void init(){
    isp['(']=1, isp[')']=6;  isp['&']=isp['|']=isp['!']=5;
    icp['(']=6, icp[')']=1;  icp['&']=icp['|']=icp['!']=5;
    isp['#']=icp['#']=0;
}
char doit(){
    int len=strlen(str);
    str[len]='#';
    str[++len]=0;

    int ptop=-1,qtop=-1,i=0;
    bool tmp;
    p[++ptop]='#';

    while(i<len){
        //printf("%c ",str[i]);
        if(str[i]=='f'){
            tmp=false;
            q[++qtop]=tmp;
            i++;
        }
        else if(str[i]=='t'){
            tmp=true;
            q[++qtop]=tmp;
            i++;
        }
        else if(icp[str[i]]>isp[p[ptop]]) p[++ptop]=str[i++];
        else{
            char ch=p[ptop--];
            if(ch=='('||ch=='#') i++;
            else {
                if(ch=='!') q[qtop]=!q[qtop];
                else if(ch=='|'){
                    q[qtop-1]|=q[qtop];
                    qtop--;
                }
                else if(ch=='&'){
                    q[qtop-1]&=q[qtop];
                    qtop--;
                }
            }
        }
    }
    return q[qtop]?'t':'f';
}
int main(){
    //freopen("in.2.cpp","r",stdin);
    int T,cas=1;
    init();
    scanf("%d",&T);
    while(T--){
        char ss[5];
        scanf("%s%*s%s",str,ss);
        printf("%d: %s brain\n",cas++,doit()==ss[0]?"Good":"Bad");
    }
    return 0;
}
