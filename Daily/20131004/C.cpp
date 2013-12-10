#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=100;

char str[maxn];
int n;


int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%s",str)&&str[0]!='#')
    {
        n=strlen(str);
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=0;i<n;i++)
        if(str[i]=='Y')cnt1++;
        else if(str[i]=='N')cnt2++;
        else if(str[i]=='A')cnt3++;
        if(cnt3*2>=n)printf("need quorum\n");
        else if(cnt1>cnt2)printf("yes\n");
        else if(cnt1<cnt2)printf("no\n");
        else printf("tie\n");
    }
    return 0;
}
