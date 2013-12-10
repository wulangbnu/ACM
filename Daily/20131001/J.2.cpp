#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const ll INF=1000000000;
const ll N=100000+10;
ll cnt,ans;
struct Operation{
    string name;
    ll x;
}op[N];
ll q[N];
ll myabs(ll x){
    return x>0?x:-x;
}
bool doit(ll x){
    ll top=0;
    q[top++]=x;
    for(ll i=0;i<cnt;i++){
        if(op[i].name=="NUM") q[top++]=op[i].x;
        else if(op[i].name=="POP"){
            if(top<=0) return false;
            top--;
        }
        else if(op[i].name=="INV") q[top-1]*=-1;
        else if(op[i].name=="DUP"){
            if(top<=0) return false;
            q[top]=q[top-1];
            top++;
        }
        else if(op[i].name=="SWP"){
            if(top<2) return false;
            swap(q[top-1],q[top-2]);
        }
        else if(op[i].name=="ADD"){
            if(top<2) return false;
            q[top-2]+=q[top-1];
            top--;
        }
        else if(op[i].name=="SUB"){
            if(top<2) return false;
            q[top-2]-=q[top-1];
            top--;
        }
        else if(op[i].name=="MUL"){
            if(top<2) return false;
            q[top-2]*=q[top-1];
            top--;
        }
        else if(op[i].name=="DIV"){
            if(top<2) return false;
            if(q[top-1]==0) return false;
            q[top-2]/=q[top-1];
            top--;
        }
        else if(op[i].name=="MOD"){
            if(top<2) return false;
            if(q[top-1]==0) return false;
            q[top-2]%=q[top-1];
            top--;
        }
        else return false;
        if(top>0&& myabs(q[top-1])>INF ) return false;
    }
    if(top!=1) return false;
    ans=q[0];
    return true;
}
int main(){
    freopen("in.cpp","r",stdin);
    string ss;
    while(cin>>ss&&ss!="QUIT"){
        cnt=0;
        while(ss!="END"){
            op[cnt].name=ss;
            if(ss=="NUM") cin>>op[cnt].x;
            cnt++;
            cin>>ss;
        }
        //for(int i=0;i<cnt;i++) cout<<op[i].name<<endl;

        ll T,x;
        cin>>T;
        while(T-->0){
            cin>>x;
            if(!doit(x)) puts("ERROR");
            else cout<<ans<<endl;
        }
        puts("");
    }
    return 0;
}
