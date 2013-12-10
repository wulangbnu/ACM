#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int N=30+10;
set<int> st;
int a[N][N];
int n,m,k,p;
bool check(){
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<k;j++){
            if(a[i][j]>0){
                if(st.count(a[i][j])) flag=true;
            }
            else{
                if(st.count(-a[i][j])==0) flag=true;
            }
        }
        if(!flag) return false;
    }
    return true;
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,i,j;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        st.clear();
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)
        for(j=0;j<k;j++){
            scanf("%d",&a[i][j]);
        }
       scanf("%d",&p);
       for(i=0;i<p;i++){
            scanf("%d",&j);
            st.insert(j);
       }
        if(check()) puts("Yes");
        else puts("No");
    }
    return 0;
}
