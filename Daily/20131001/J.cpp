#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=100005;
typedef long long ll;
const int maxx=1000000000;

int m,T,n;
ll stack[maxn];
int top;
struct OP {
    string opt;
    ll x;
    bool input() {
        cin>>opt;
        if(opt=="NUM")cin>>x;
        else x=-1;
        return 1;
    }
    bool solve() {
        if(opt=="NUM") {
            stack[++top]=x;
            return 1;
        } else if(opt=="POP") {
            if(top==0)return 0;
            top--;
            return 1;
        } else if(opt=="INV") {
            if(top==0)return 0;
            stack[top]=-stack[top];
            return 1;
        } else if(opt=="DUP") {
            if(top==0)return 0;
            stack[top+1]=stack[top];
            top++;
            return 1;
        } else if(opt=="SWP") {
            if(top<2)return 0;
            swap(stack[top],stack[top-1]);
            return 1;
        } else if(opt=="ADD") {
            if(top<2)return 0;
            stack[top-1]+=stack[top];
            top--;
            if(stack[top]>maxx||stack[top]<-maxx)return 0;
            return 1;
        } else if(opt=="SUB") {
            if(top<2)return 0;
            stack[top-1]-=stack[top];
            top--;
            if(stack[top]>maxx||stack[top]<-maxx)return 0;
            return 1;
        } else if(opt=="MUL") {
            if(top<2)return 0;
            stack[top-1]*=stack[top];
            top--;
            if(stack[top]>maxx||stack[top]<-maxx)return 0;
            return 1;
        } else if(opt=="DIV") {
            if(top<2)return 0;
            if(stack[top]==0)return 0;
            stack[top-1]/=stack[top];
            top--;
            return 1;
        } else if(opt=="MOD") {
            if(top<2)return 0;
            if(stack[top]==0)return 0;
            stack[top-1]%=stack[top];
            top--;
            return 1;
        }
        return 1;
    }
} op[maxn];

int main() {
   //freopen("in.cpp","r",stdin);
    while(op[0].input()) {
        if(op[0].opt=="QUIT")break;
        m++;
        if(op[0].opt!="END"){
        while(op[m].input()) {
            if(op[m].opt=="END")break;
            m++;
        }
        }
        scanf("%d",&T);
        while(T--) {
            top=0;
            scanf("%d",&n);
            stack[++top]=n;
            bool sign=0;
            for(int i=0;i<m;i++)
            {
                if(!op[i].solve())
                {
                    sign=1;
                    break;
                }
            }
            if(sign||top!=1)printf("ERROR\n");
            else printf("%lld\n",stack[1]);
        }
        m=0;
        printf("\n");
    }
    return 0;
}
