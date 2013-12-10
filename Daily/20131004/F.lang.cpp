#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
int shape[7][4]={
0,1,2,3,
0,1,2,4,
0,1,2,5,
0,1,2,6,
0,1,5,6,
0,1,4,5,
1,2,4,5,
};
int a[4][4];
vector<ll> state[7];
set<ll> st;
char str[5];
ll ans;
void rotate(){
    int b[4][4];
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    b[j][3-i]=a[i][j];
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    a[i][j]=b[i][j];
}
void doit(int x,int y,int s,int t,int id){
    vector<int> pos;
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
        if(a[i][j]==0) continue;
        int xx=i-x+s, yy=j-y+t;
        if(xx>=0&&xx<6&&yy>=0&&yy<6) pos.push_back(xx*6+yy);
    }
    if(pos.size()==4){
        ll k=0;
        for(int i=0;i<4;i++) k|=1ll<<(35-pos[i]);
        state[id].push_back(k);

//        if(id==0){
//            for(int i=0;i<4;i++) cout<<pos[i]<<" ";cout<<endl;
//            cout<<"~~~"<<k<<endl;
//        }
    }
}
void init(int id){
    memset(a,0,sizeof(a));
    for(int i=0;i<4;i++){
        int x=shape[id][i];
        a[x/4][x%4]=1;
    }
    for(int i=0;i<4;i++){
        int x,y;
        for(int j=0;j<4;j++)
        for(int k=0;k<4;k++){
            if(a[j][k]) x=j, y=k;
        }
        for(int j=0;j<6;j++)
        for(int k=0;k<6;k++)
        doit(x,y,j,k,id);
        rotate();
    }
    sort(state[id].begin(),state[id].end());
    state[id].erase(unique(state[id].begin(),state[id].end()),state[id].end());
    //cout<<state[id].size()<<endl;
}
void dfs(int dep,ll now,int type){
    if(dep==3){
        if(type){
            if(st.count(now)) ans=max(ans,now);
        }
        else st.insert(now);
        return;
    }
    int id=str[2-dep]-'A';
    for(int i=0;i<state[id].size();i++){
        if(now&state[id][i]) continue;
        dfs(dep+1,now|state[id][i],type);
    }
}
void output(int cas){
    printf("%d\n",cas);
    if(ans==-1) puts("No solution");
    else {
        for(int i=0;i<6;i++,puts(""))
        for(int j=0;j<6;j++)
        printf("%c",((ans>>(35-i*6-j))&1)?'#':'.');
    }
}
int main(){
    //freopen("in.cpp","r",stdin);
    for(int i=0;i<7;i++) init(i);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        st.clear();
        ans=-1;
        scanf("%s",str);
        dfs(0,0,0);
        scanf("%s",str);
        dfs(0,0,1);
        output(cas++);
    }
    return 0;
}
