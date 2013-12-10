#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=200000+10;
int n,a[N][3];
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        int Max[3]={0};
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            sort(a[i],a[i]+3);
            for(int j=0;j<3;j++) Max[j]=max(Max[j],a[i][j]);
        }

        vector<int> s;
        for(int i=1;i<=n;i++){
            if(a[i][1]>Max[0]&&a[i][2]>Max[1]) s.push_back(i);
        }
        printf("%d\n",s.size());
        for(int i=0;i<s.size();i++)
        printf("%d%c",s[i],i==s.size()-1?'\n':' ');
    }
    return 0;
}
