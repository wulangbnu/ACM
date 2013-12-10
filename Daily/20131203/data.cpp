#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    #ifdef wulang
        freopen("in.cpp","w",stdout);
    #endif

    int n=10000;
    cout<<n<<" "<<10000000<<endl;
    for(int i=1;i<n;i++) cout<<i<<" "<<i+1<<" "<<100<<endl;
    return 0;
}

