#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=20;

char str[maxn];
int vis[maxn];
int n,pos;

int change(char c)
{
    if(c>='A'&&c<='F')return c-'A'+10;
    return c-'0';
}
void output(int x)
{
    if(x<10)printf("%d",x);
    else printf("%c",x-10+'A');
}

void solve()
{
    for(int i=pos;i>=1;i--)
    {
        int x=change(str[i-1]);
        for(int j=x+1;j<16;j++)
        {
            if(vis[i-1]&(1<<j))continue;
            for(int k=1;k<i;k++)printf("%c",str[k-1]);
            int sy=vis[i-1]|(1<<j);
            output(j);
            for(int k=i+1;k<=n;k++)
            {
                for(int r=0;r<16;r++)
                {
                    if(sy&(1<<r))continue;
                    output(r);
                    sy|=(1<<r);
                    break;
                }
            }
            printf("\n");
            return;
        }
    }
    printf("10");
    for(int i=1;i<=n-1;i++)
    output(i+1);
}

int main(){
    //freopen("in.cpp","r",stdin);
    scanf("%s",str);
    n=strlen(str);
    for(int i=1;i<=n;i++)
    vis[i]=vis[i-1]|(1<<(change(str[i-1])));
    pos=n;
    for(int i=1;i<=n;i++)
    if(vis[i-1]&(1<<change(str[i-1])))
    {
        pos=i;
        break;
    }
    solve();
    return 0;
}
