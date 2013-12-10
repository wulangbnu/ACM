#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000000+10;
char str[N],str2[N];
int next[N];
void get_next(char t[])
{
    int i=0,j=-1;
    next[0]=-1;
    while(t[i]){
        if(j==-1||t[i]==t[j]) next[++i]=++j;
        else j=next[j];
    }
}
int kmp(char *s,char *t)
{
    int i=0,j=0,cnt=0;
    while(s[i]&&(j==-1||t[j])){
        if(j==-1||s[i]==t[j]) i++,j++;
        else j=next[j];
        if(j!=-1&&!t[j]) cnt++,j=next[j];
    }
    return cnt;
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d ",&T);
    while(T--){
        gets(str);
        gets(str2);
        get_next(str2);
        printf("Case %d: %d\n",cas++,kmp(str,str2));
    }
    return 0;
}
