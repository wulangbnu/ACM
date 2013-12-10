#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 2147483647;
const int MAXN=200000+10;
bool cmp(const int &x,const int &y){
    return x>y;
}
struct Heap{
    int _v[MAXN];
    int size;
    void push(int a){
        _v[size++]=a;
       if(size>1) push_heap(_v,_v+size,cmp);
    }
    void pop(){
        pop_heap(_v,_v+size,cmp);
        size--;
    }
    int top(){
        return _v[0];
    }
    void init(){
        size=0;
    }
    bool empty(){
        return size==0;
    }
}Q;
vector<int>ans;
int N,K;
int a_1,a0,A,B,C;
int main(){
    //freopen("in.cpp","r",stdin);
    while(~scanf("%d%d",&N,&K)){
        scanf("%d%d%d%d%d",&a_1,&a0,&A,&B,&C);
        Q.init();
        for(int i=0; i<N; ++i){
            int x = ((ll)A*a_1+(ll)B*a0+C)&MOD;
            //printf("%d\n",x);
            if(Q.size<K) Q.push(x);
            else{
                if(Q.top()<x){
                    Q.pop();
                    Q.push(x);
                }
            }
            a_1 = a0; a0=x;
        }
        ans.clear();
        while(!Q.empty()){
            ans.push_back( Q.top() );
            Q.pop();
        }
        printf("%d",ans[ans.size()-1]);
        for(int i=ans.size()-2; i>=0; --i)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
