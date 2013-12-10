#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
const int N=100;
ll fe[N];
void init(){
    fe[0]=0;
    fe[1]=1;
    for(int i=2;i<N;i++){
        fe[i]=fe[i-1]+fe[i-2];
//        cout<<fe[i]<<endl;
//        if(fe[i]>(1ll<<63)) printf("~~~ %d\n",i);
    }

    for(int i=0;i<N;i++){
        printf("\"");
        for(ll k=2;k*k<=fe[i];k++){
            while(fe[i]%k==0){
                printf(" %lld",k);
                fe[i]/=k;
            }
        }
        if(fe[i]>1) printf(" %lld",fe[i]);
        puts("\",");
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    freopen("out.cpp","w",stdout);
    init();
    return 0;
}
