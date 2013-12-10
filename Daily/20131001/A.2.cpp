#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N=5000+10;
int a[1000+10][5],b[N],n,next[N];
ll Mod ;
void init(){
    int cnt=1;
    for(int i=1;i<=n;i++){
        a[i][0]=cnt++;
        a[i][1]=cnt++;
    }
    for(int i=1;i<=n;i++){
        a[i][2]=cnt++;
        a[i][3]=cnt++;
    }
    for(int i=1;i<=n;i++) a[i][4]=cnt++;

    for(int i=1;i<=n;i++)
    for(int j=0;j<5;j++){
        next[a[i][j]]=(i-1)*5+j+1;
        b[a[i][j]]=i;
    }
}
vector<int> path[6];
vector<int> con;
int pos[6],re[6];
void work(int x,int val){
    pos[val]=x;
    path[val].clear();
    con.clear();
    con.push_back(x);

    int y=next[x];
    while(y!=x){
        con.push_back(y);
        y=next[y];
    }
    re[val]=con.size();
    for(int i=0;i<con.size();i++) path[val].push_back(b[con[i]]);
}
vector<int> people[1000+10][6];
void pre_doit(){
    for(int i=1;i<=n;i++)
    for(int j=0;j<=5;j++)
    people[i][j].clear();

    for(int i=1;i<=5;i++)
    for(int j=0;j<path[i].size();j++)
    people[path[i][j]][i].push_back(j+1);
}
ll ans;
int xx;
int aa[6],bb[6];


void gcd(ll a, ll b, ll& d, ll& x, ll& y){
    if (!b){d = a;x = 1; y = 0;}
    else{gcd(b, a%b, d, y, x); y -= a / b * x;}
}
bool solve(ll &m0, ll &a0, int m, int a){
    ll y, x, g;
    gcd(m0, m, g, x, y);
    if (abs(a - a0) % g) return 0;
    x *= (a - a0) / g;
    x %= m / g;
    a0 = (x * m0 + a0);
    m0 *= m / g;
    a0 %= m0;
    if (a0 < 0) a0 += m0;
    return 1;
}
ll China_Reminder(int m[], int r[], int n){
    ll m0 = 1, a0 = 0;
    for (int i = 0;i < n;i++){
        if (!solve(m0, a0, m[i], r[i])) return -1;
    }
    return a0;
}




void doit(int x){
    for(int i=1;i<=5;i++) if(people[x][i].size()==0) return;

    for(int i=0;i<5;i++) aa[i]=re[i+1];

    for(int i=0;i<people[x][1].size();i++)
    for(int j=0;j<people[x][2].size();j++)
    for(int r=0;r<people[x][3].size();r++)
    for(int s=0;s<people[x][4].size();s++)
    for(int t=0;t<people[x][5].size();t++){
        bb[0]=people[x][1][i];
        bb[1]=people[x][2][j];
        bb[2]=people[x][3][r];
        bb[3]=people[x][4][s];
        bb[4]=people[x][5][t];
        ll ret=China_Reminder(aa,bb,5);
        if(ret!=-1&&(ans==-1||ret<ans)){
            ans=ret;
            xx=x;
        }
    }
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
    while(scanf("%d",&n)&&n){
        init();
        //for(int i=1;i<=5*n;i++) printf("%d %d %d\n",i,next[i],re[i]);
        for(int j,i=1;i<=5*n;i++){
            getint(j);
            if(j<=5) work(i,j);
        }
        pre_doit();
        ans=-1;
        for(int i=1;i<=n;i++) doit(i);
        if(ans==-1) puts("Neverending game.");
        else{
            ans=max(ans,1ll);
            printf("Player %d wins game number %lld.\n",xx,ans);
        }
    }
    return 0;
}
