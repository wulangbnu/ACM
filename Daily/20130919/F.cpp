#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int N=100000+10;
multiset<int> st;
int n,s,w,q;
int a[N],b[N],p[N];
void init(){
    int g = s;
    for(int i=0; i<n; i++) {
          a[i] = (g/7) % 10;
          if( g%2 == 0 ) { g = (g/2); }
          else           { g = (g/2) ^ w; }
    }
    p[0]=1;
    for(int i=1;i<=n;i++) p[i]=10*p[i-1]%q;
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%d%d%d%d",&n,&s,&w,&q)&&(n+s+w+q)){
        init();
        st.clear();
        for(int k=0,i=n-1;i>=0;i--){
            k=(k+a[i]*p[n-1-i])%q;
            b[i]=k;
            if(a[i]>0) st.insert(b[i]);
        }
        int ans=0;
        for(int k=0,i=n-1;i>=0;i--){
            ans+=st.count(k);
            if(a[i]>0) st.erase(st.find(b[i]));
            k=b[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
