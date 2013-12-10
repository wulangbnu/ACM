#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=300000+10;
int a[N],n,k;
bool check(int &mid){
    bool flag=true;
    for(int i=1;i<=n;i++)
    if(a[i]%mid>k){
        mid=a[i]/(a[i]/mid+1);
        flag=false;
    }
    return flag;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d",&n,&k)+1){
        int y=1000000+10;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            y=min(y,a[i]);
        }
        while(!check(y));
        printf("%d\n",y);
    }
    return 0;
}
