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
int pos[6],re[6];
void work(int x,int val){
    pos[val]=x;
    path[val].clear();
    vector<int> con;
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
ll aa[6],bb[6];


ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll Extend_Euclid(ll a, ll b, ll&x, ll& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll d = Extend_Euclid(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - a/b*y;
    return d;
}
//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
    ll x,y;
    ll t = Extend_Euclid(a,n,x,y);
    if(t != 1)
        return -1;
    return (x%n+n)%n;
}
//将两个方程合并为一个
bool merge(ll a1, ll n1, ll a2, ll n2, ll& a3, ll& n3)
{
    ll d = gcd(n1,n2);
    ll c = a2-a1;
    if(c%d)
        return false;
    c = (c%n2+n2)%n2;
    c /= d;
    n1 /= d;
    n2 /= d;
    c *= inv(n1,n2);
    c %= n2;
    c *= n1*d;
    c += a1;
    n3 = n1*n2*d;
    a3 = (c%n3+n3)%n3;
    return true;
}
//求模线性方程组x=ai(mod ni),ni可以不互质
ll China_Reminder2(int len, ll* a, ll* n)
{
    ll a1=a[0],n1=n[0];
    ll a2,n2;
    for(int i = 1; i < len; i++)
    {
        ll aa,nn;
        a2 = a[i],n2=n[i];
        if(!merge(a1,n1,a2,n2,aa,nn))
            return -1;
        a1 = aa;
        n1 = nn;
    }
    Mod = n1;
    return (a1%n1+n1)%n1;
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
        ll ret=China_Reminder2(5,bb,aa);
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
