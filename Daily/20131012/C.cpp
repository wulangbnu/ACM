#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long ll;
const ll P=10007;
const int N=10000+10;
ll mp[N][16];
ll seed[100];
int len[N][16];
int n,m;
void init(){
    seed[0]=1;
    for(int i=1;i<100;i++) seed[i]=seed[i-1]*P;
}
ll hash_ll(char str[]){
    ll ret=0;
    for(int i=0;str[i];i++){
        ret=ret*P+str[i];
    }
    return ret;
}
char str[100],ss[100];
void doit(int id){
    for(int s=-1,i=0;i<m;i++){
        int k=0;
        for(s++;str[s];s++){
            if(str[s]==',') break;
            ss[k++]=str[s];
        }
        ss[k]=0;
        //puts(ss);
        len[id][i]=k;
        mp[id][i]=hash_ll(ss);
    }
}

const ll MOD=P;
struct Hash{
    int first[MOD],next[N],cost[N],tot;
    ll _v[N];
    void init(){
        memset(first,-1,sizeof(first));
        tot=0;
    }
    void insert(ll x,int w=0){
        _v[tot]=x;
        cost[tot]=w;
        int pt=x%MOD;
        next[tot]=first[pt];
        first[pt]=tot++;
    }
    int find(ll x){
        for(int i=first[x%MOD];i+1;i=next[i])
        if(_v[i]==x) return cost[i];
        return -1;
    }
}hash;
bool solve(int x,int y){
    hash.init();
    for(int i=0;i<n;i++){
        int tmp=len[i][y];
        ll val=mp[i][x]*seed[tmp+1]+23*seed[tmp]+mp[i][y];
        int vv=hash.find(val);
        if(vv!=-1){
            puts("NO");
            printf("%d %d\n",vv+1,i+1);
            printf("%d %d\n",x+1,y+1);
            return true;
        }
        hash.insert(val,i);
    }
    return false;
}
int main(){
    //freopen("in.cpp","r",stdin);
    init();
    while(scanf("%d%d",&n,&m)+1){
        gets(str);
        for(int i=0;i<n;i++){
            gets(str);
            doit(i);
        }

        int f=1;
        for(int i=0;i<m&&f;i++)
        for(int j=i+1;j<m&&f;j++){
            if(solve(i,j)) f=0;
        }
        if(f) puts("YES");

    }
    return 0;
}
