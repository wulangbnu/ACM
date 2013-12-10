#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;
const int maxn=1005;

int n,a[maxn],m;
vector<int>ans[maxn];

int main() {
    //freopen("in.cpp","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        m+=a[i];
    }
    sort(a+1,a+n+1);
    double ret=0;
    for(int i=1; i<=n; i++) {
        int sum=0;
        for(int j=m; j>m-a[i]; j--) {
            sum+=j;
            ans[i].push_back(j);
        }
        ret+=sum*1.0/a[i];
        m-=a[i];
    }
    printf("%.5f\n",ret);
    for(int i=1; i<=n; i++) {
        bool sign=0;
        for(int j=0; j<ans[i].size(); j++) {
            if(sign)printf(" ");
            else sign=1;
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
