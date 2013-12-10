#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N=1000000+10;
int n,a[N],pos[N],pre[N];
vector<int> vi[N];
bool get[N];
set<int> st;
set<int>:: iterator it;
int find(int x){
    return pre[x]==x?x:pre[x]=find(pre[x]);
}
void inline work(int i,int j){
    i=find(i);
    j=find(j);
    pre[i]=j;
}
void doit(){

    for(int i=1;i<=n;i++) pre[i]=i;

    st.clear();
    st.insert(N);
    memset(get,false,sizeof(get));
    for(int x,i=1;i<=n;i++){
        if(get[a[i]+1]) x=a[i]+1;
        else{
            it=st.lower_bound(a[i]);
            x=*it;
        }
        if(x!=N) work(x,a[i]);
        st.insert(a[i]);
        get[a[i]]=true;
    }

    st.clear();
    st.insert(-1);
    memset(get,false,sizeof(get));
    for(int x,i=n;i>=1;i--){
        if(get[a[i]-1]) x=a[i]-1;
        else{
            it=st.lower_bound(a[i]);
            x=*--it;
        }
        if(x!=-1) work(x,a[i]);
        st.insert(a[i]);
        get[a[i]]=true;
    }

}
void pt(int x){
    if(get[x]) return;
    get[x]=true;
    int m=vi[x].size();
    printf("%d",m);
    for(int j=0;j<m;j++) printf(" %d",vi[x][j]);
    puts("");
}
void output(){

    for(int i=1;i<=n;i++)  vi[i].clear();
    for(int i=1;i<=n;i++)  vi[find(i)].push_back(i);

    int cnt=0;
    for(int i=1;i<=n;i++) if(vi[i].size()>0) cnt++;
    printf("%d\n",cnt);

    memset(get,false,sizeof(get));
    for(int i=1;i<=n;i++) pt(find(i));

}
void getint(int &x){
    x=0;
    char ch=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}
int main(){

    freopen("in.cpp","r",stdin);
    while(scanf("%d",&n)+1){
        for(int i=1;i<=n;i++) getint(a[i]);
        doit();
        output();
    }
    return 0;
}
