#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
const int N=600000+10;
const int M=7000+10;
int le[N],ri[N],n,a[N],pos[N];
char q[2*N],str[M];
int cnt,pre[M];
void dfs(int x){
//    q[cnt++]=(x&1)+'0';
//    //printf("%d ",x);
//    if(le[x]!=-1){
//        dfs(le[x]);
//        q[cnt++]=(x&1)+'0';
//        //printf("%d ",x);
//    }
//    if(ri[x]!=-1){
//        dfs(ri[x]);
//        q[cnt++]=(x&1)+'0';
//        //printf("%d ",x);
//    }
    stack<int> s;
    s.push(x);
    while(!s.empty()){
        int x=s.top();
        s.pop();
        if(x>N){
            q[cnt++]=x-N;
            continue;
        }
        q[cnt++]=(x&1)+'0';
        if(ri[x]!=-1){
            s.push((x&1)+'0'+N);
            s.push(ri[x]);
        }
        if(le[x]!=-1){
            s.push((x&1)+'0'+N);
            s.push(le[x]);
        }
    }
}
void build(){
    memset(le,-1,sizeof(le));
    memset(ri,-1,sizeof(ri));
    set<int> st;
    set<int> ::iterator it;
    st.insert(-N);
    st.insert(N);
    st.insert(a[1]);
    int root=a[1];
    for(int i=2;i<=n;i++){
        it=st.lower_bound(a[i]);
        int y=*it;
        it--;
        int x=*it;
        if(x!=-N&&y!=N){
            if(pos[y]<pos[x]) ri[x]=a[i];
            else le[y]=a[i];
        }else if(y==N) ri[x]=a[i];
        else le[y]=a[i];
        st.insert(a[i]);
    }
    cnt=0;
    dfs(root);
    q[cnt]=0;
    //puts(q);
}
int kmp(char s1[], char s2[]) {
    int i, j, ans = 0;
    j = -1; pre[0] = -1;
    for (i = 1; s1[i] != 0; i++) {
        while(j >= 0 && s1[j+1] != s1[i]) j = pre[j];
        if (s1[j+1] == s1[i]) pre[i] = j+1;
        else pre[i] = j;
        j = pre[i];
    }

    j = -1;
    for (i = 0; s2[i] != 0; i++) {
        while (j >= 0 && s1[j+1] != s2[i]) j = pre[j];
        if (s1[j+1] == s2[i]) j++;
        if (s1[j+1] == 0) {
           ans++;
           j = pre[j];
        }
    }
    return ans;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) pos[a[i]]=i;
        build();
        scanf("%s",str);
//        puts(q);
//        puts(str);
        printf("Case #%d: %d\n",++cas,kmp(str,q));
    }
    return 0;
}
