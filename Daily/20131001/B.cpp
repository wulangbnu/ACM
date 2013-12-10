#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char s[1005],t[100005];

int main(){
 // freopen("in.cpp","r",stdin);
    while(scanf("%s",s))
    {
        if(s[0]=='0')break;
        scanf("%s",t);
        int ls=strlen(s);
        int lt=strlen(t);
        int pos=0;
        for(int i=0;i<lt;i++)
        {
            int tt=s[pos++]-'A'+1;
            t[i]=(t[i]-'A'+tt)%26+'A';
            if(pos==ls)pos=0;
        }
        printf("%s\n",t);
    }
    return 0;
}
