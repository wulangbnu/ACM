#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    int n,m,k;
    while(cin>>n>>m>>k){
        int ans=0;
        while(n--){
            int x;
            cin>>x;
            if(x==1){
                if(m>0) m--;
                else ans++;
            }else{
                if(k>0) k--;
                else if(m>0) m--;
                else ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
