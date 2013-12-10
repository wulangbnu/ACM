#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N=100000;
int p[N],cnt;
void init(){
    p[0]=p[1]=1;
    for(int i=2;i<N;i++){
        if(p[i]) continue;
        for(int j=i+i;j<N;j+=i)
        p[j]=1;
    }
    for(int i=0;i<N;i++)
    if(!p[i]) p[cnt++]=i;
    //for(int i=0;i<10;i++) cout<<p[i]<<" ";
}
void work(int n,map<int,ll>& v){
    for(int i=0;i<cnt;i++){
        if(p[i]>n) break;
        if(n%p[i]==0){
            ll cnt=0;
            while(n%p[i]==0){
                cnt++;
                n/=p[i];
            }
            v[p[i]]=cnt;
        }
    }
    if(n>1) v[n]=1;
}
bool doit(int a,int b,int c,int d){
    init();
    map<int,ll> va,vc;
    work(a,va);
    work(c,vc);
    for(map<int,ll>::iterator it=vc.begin();it!=vc.end();it++){
        int x=it->first;
        ll y=it->second;
        if(va.count(x)==0) return false;
        if(va[x]*b<y*d) return false;
    }
    return true;
}
struct BigFatInteger2{
    string isDivisible(int A, int B, int C, int D){
        if(doit(A,B,C,D)) return "divisible";
        else return "not divisible";
    }
};
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif

    init();
    return 0;
}
