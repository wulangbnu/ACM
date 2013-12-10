#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=105;

int n,a[maxn];

int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        bool sign=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            int c=a[i]-a[i-1];
            for(int j=0;j<c;j++)
            {
                if(sign)printf(" ");
                else sign=1;
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
