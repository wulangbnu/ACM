#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)==1){
        set<int> st;
        st.insert(1);
        int inf=2*n*n;
        for(int i=2;st.size()<n;i++){
            for(set<int>::iterator it=st.begin();it!=st.end();it++){
                int x=(*it)*i;
                if(x<inf) st.insert(x);
            }
        }
        int k=0;
        for(set<int>::iterator it=st.end();k<n;k++){
            printf("%d%c",*(--it),k==n-1?'\n':' ');
        }
    }
    return 0;
}
