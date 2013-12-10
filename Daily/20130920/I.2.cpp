#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
const int N=50+10;
char str[N][N],mask[N][N],mask2[N][N];
set<string> st;
vector<string> vs[4];
string ss[4],s;
int n;
void doit1(int index){
    ss[index]="";
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        if(mask[i][j]=='*'){
            if(str[i][j]=='.') str[i][j]=' ';
            ss[index]+=str[i][j];
        }
    }

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        mask2[j][n-1-i]=mask[i][j];
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        mask[i][j]=mask2[i][j];
    }
}
void doit2(int index){
    s="";
    vs[index].clear();
    for(int i=0;i<4;i++)
    s+=ss[(i+index)%4];
    istringstream in(s);
    while(in>>s) vs[index].push_back(s);
}
bool check(int x){
    if(vs[x].size()==0) return false;
    for(int i=0;i<vs[x].size();i++)
    if(st.count(vs[x][i])==0) return false;
    return true;
}
bool cmp(int x,int y){
    for(int i=0;i<vs[x].size()&&i<vs[y].size();i++)
    if(vs[x][i]!=vs[y][i]) return vs[x][i]<vs[y][i];
    return vs[x].size()<vs[y].size();
}
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        for(int i=0;i<n;i++) scanf("%s",mask[i]);

        for(int i=0;i<4;i++) doit1(i);

        st.clear();
        int m;
        scanf("%d",&m);
        while(m--){
            scanf("%s",str[0]);
            st.insert(string(str[0]));
        }

        for(int i=0;i<4;i++) doit2(i);
        int ans=-1;
        for(int i=0;i<4;i++){
            if(check(i)&&(ans==-1||cmp(i,ans))) ans=i;
        }

        printf("Case #%d: ",cas++);
        if(ans<0) puts("FAIL TO DECRYPT");
        else{
            for(int i=0;i<vs[ans].size();i++)
            printf("%s%c",vs[ans][i].c_str(),i==vs[ans].size()-1?'\n':' ');
        }
    }
    return 0;
}
