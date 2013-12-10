#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;
const int maxn=255;
typedef long long ll;

ll c[maxn];
int a,b,n;

int main(){
    //freopen("in.cpp","r",stdin);
    srand(time(NULL));
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&n);
        for(int i=0;i<n;i++)scanf("%lld",&c[i]);
        int ti=130000;
        bool yes=0;
        while(ti--)
        {
            ll sum=0;
            for(int i=0;i<n;i++)
            {
                int x=rand()%2;
                if(x)sum+=c[i];
            }
            if(sum>=a&&sum<=b)
            {
                yes=1;
                break;
            }
        }
        if(yes)puts("Saintow swaintow swaintows.");
        else puts("Saintow swaintow waintows in dust.");
    }
    return 0;
}
