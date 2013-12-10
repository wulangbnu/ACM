#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const ll N=200000+10;
string mon[]={"##","Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov","Dec"};
ll md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll n,m,t,s,cost[N];
struct Point{
    ll h,v;
    ll ans;
}p[2500+10];
bool check(ll x){
    return x%400==0||(x%4==0&&x%100!=0);
}
ll input(ll &h,ll &r){
    //Jan 1 2000 9 10
    string ss;
    ll day,month,year;
    cin>>ss;
    scanf("%lld%lld%lld%lld",&day,&year,&h,&r);
    for(ll i=1;i<=12;i++)
    if(mon[i]==ss){
        month=i;
        break;
    }

    ll tot=0;
    for(ll i=2000;i<year;i++) tot+=365+check(i);
    for(ll i=1;i<month;i++){
        tot+=md[i];
        if(i==2&&check(year)) tot++;
    }

    tot+=day-1;
    tot*=24;
    tot+=h+1;
    h=tot;

    return 0;
    //prllf("~~~%d %d\n",h,r);
}

//线段树区间修改 区间最大值
struct Node{
    ll left,right,val;
    ll add;
}tree[N*5];
void build(ll k,ll left,ll right){
    tree[k].left=left;
    tree[k].right=right;
    tree[k].add=0;
    if(left==right) tree[k].val=cost[left];
    else{
        ll mid=(left+right)>>1;
        build(2*k,left,mid);
        build(2*k+1,mid+1,right);
        tree[k].val=min(tree[2*k].val,tree[2*k+1].val);
    }
}
void insert(ll k,ll left,ll right,ll val){
    if(tree[k].left==left&&tree[k].right==right){
        tree[k].add+=val;
        tree[k].val+=val;
    }
    else{
        ll mid=(tree[k].left+tree[k].right)>>1;
        if(tree[k].add>0){
            insert(2*k,tree[k].left,mid,tree[k].add);
            insert(2*k+1,mid+1,tree[k].right,tree[k].add);
            tree[k].add=0;
        }
        if(mid>=right) insert(2*k,left,right,val);
        else if(mid+1<=left) insert(2*k+1,left,right,val);
        else{
            insert(2*k,left,mid,val);
            insert(2*k+1,mid+1,right,val);
        }
        tree[k].val=min(tree[2*k].val,tree[2*k+1].val);
    }
}
ll query(ll k,ll left,ll right){
    if(tree[k].left==left&&tree[k].right==right) return tree[k].val;
    ll mid=(tree[k].left+tree[k].right)>>1;
    if(tree[k].add>0){
        insert(2*k,tree[k].left,mid,tree[k].add);
        insert(2*k+1,mid+1,tree[k].right,tree[k].add);
        tree[k].add=0;
    }
    if(mid>=right) return query(2*k,left,right);
    else if(mid+1<=left) return query(2*k+1,left,right);
    else return min(query(2*k,left,mid),query(2*k+1,mid+1,right));
}

int main(){

    //freopen("in.cpp","r",stdin);
    while(scanf("%lld%lld",&n,&m)&&n+m){
        for(ll i=1;i<=n;i++) input(p[i].h,p[i].v);
        scanf("%lld%lld",&t,&s);
        for(ll i=1;i<=m;i++) scanf("%lld",&cost[i]);
        for(ll i=m+1;i<=m+t;i++) cost[i]=(1ll<<50);

        for(ll i=0;i<=t;i++){
            if(p[1].h-i<1) break;
            cost[p[1].h-i]+=i*s;
        }

        build(1,1,m+t);
        ll k=1;

        for(ll i=p[1].h-t;i<=m;i++){

            while(k<=n&&i+t==p[k].h){
                p[k].ans=query(1,max(1ll,i),p[k].h);
                p[k].ans*=p[k].v;
                k++;
            }

            if(k>n) break;
            insert(1,max(1ll,i+1),i+t,s);
        }

        ll ans=0;
        for(ll i=1;i<=n;i++) ans+=p[i].ans;
        printf("%lld\n",ans);
    }
    return 0;
}
