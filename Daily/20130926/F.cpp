#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<map>
using namespace std;

map<string,int>mp;
string a;
int n,price;

int main(){
    //freopen("in.cpp","r",stdin);
    scanf("%d%d",&n,&price);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
       cin>>x>>a;
       sum+=x;
       mp[a]+=x;
    }
    printf("%d\n",sum);
    printf("%d\n",mp["bedroom"]);
    double tt=sum-mp["balcony"]*1.0/2;
    printf("%.8f\n",price*tt);
    return 0;
}
