#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
const int N=50+10;
vector<int> adj[N];
ll a[N],dp[N][N];
void init(){
    a[0]=1;
    for(int i=1;i<N;i++) a[i]=(a[i-1]*i)%MOD;
}
bool judge(string s1,string s2){
    if(s1.size()>=s2.size()) return false;
    for(int i=0;i<s1.size();i++)
    if(s1[i]!=s2[i]) return false;
    return true;
}
int doit(vector <string> names,int L){
    init();
    int n=names.size();
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        if(i==j) continue;
        if(judge(names[i],names[j])) adj[j].push_back(i);
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) dp[i][0]=1;
    for(int j=1;j<=L-1;j++){
        for(int i=0;i<n;i++){
            for(int k=0;k<adj[i].size();k++){
                int x=adj[i][k];
                dp[i][j]=(dp[i][j]+dp[x][j-1])%MOD;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+dp[i][L-1]*a[n-L])%MOD;
    }
    return  (int)ans;
}
struct  SimilarNames2{
    int count(vector <string> names, int L){
        return doit(names,L);
    }
};
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    vector<string> names;
    names.push_back("kenta");
    names.push_back("kentaro");
    names.push_back("ken");

    doit(names,2);


    return 0;
}
