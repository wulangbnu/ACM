#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;
const int N=150;
vector<char> adj[2];
char str[N];
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1;
    scanf(" %d ",&T);
    while(T--){
        printf("Case %d: ",cas++);
        adj[0].clear(); adj[1].clear();
        gets(str);
        for(int i=0;str[i];i++)
        if(str[i]!=' ') adj[0].push_back(tolower(str[i]));
        gets(str);
        for(int i=0;str[i];i++)
        if(str[i]!=' ') adj[1].push_back(tolower(str[i]));
        sort(adj[0].begin(),adj[0].end());
        sort(adj[1].begin(),adj[1].end());
        if(adj[0]==adj[1]) puts("Yes");
        else puts("No");
    }
    return 0;
}
