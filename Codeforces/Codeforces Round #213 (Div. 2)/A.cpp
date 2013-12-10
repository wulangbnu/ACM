#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,k;
bool tag[20];
bool check(){
    for(int i=0;i<=k;i++) tag[i]=false;
    string ss;
    cin>>ss;
    //cout<<ss<<endl;
    for(int i=0;i<ss.size();i++) tag[ss[i]-'0']=true;
    for(int i=0;i<=k;i++) if(!tag[i]) return false;
    return true;
}
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    while(scanf("%d%d",&n,&k)+1){
        int ans=0;
        while(n--){
            ans+=check();
        }
        printf("%d\n",ans);
    }
    return 0;
}
