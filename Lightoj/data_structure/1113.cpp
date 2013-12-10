#include<cstdio>
#include<cstring>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define N 50+5
stack<string> q1,q2;
char str[N];
string s;
string cur;
int cas=1;
void init()
{
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    cur="http://www.lightoj.com/";
}
int main()
{
   // freopen("in.cpp","r",stdin);

    int T,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        init();
        printf("Case %d:\n",cas++);
        while(scanf("%s",str)&&strcmp(str,"QUIT")){
            if(str[0]=='B'){
                if(q1.empty()) puts("Ignored");
                else{
                       q2.push(cur);
                       cur=q1.top();
                       q1.pop();
                       puts(cur.c_str());
                }
            }
            else if(str[0]=='F'){
                if(q2.empty()) puts("Ignored");
                else {
                        q1.push(cur);
                        cur=q2.top();
                        q2.pop();
                        puts(cur.c_str());
                }
            }
            else if(str[0]=='V'){
                q1.push(cur);
                scanf("%s",str);
                cur=str;
                while(!q2.empty()) q2.pop();
                puts(cur.c_str());
            }
        }
    }
    return 0;
}
