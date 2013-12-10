#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=10005;
int n,a[maxn];
priority_queue<int>que;
int main(){
    //freopen("in.cpp","r",stdin);
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       int x;
       scanf("%d",&x);
       que.push(x);
   }
   int ret=0;
   while(que.size()>=2&&que.top()>1&&n>=3)
   {
      int x=que.top();
      que.pop();
      int y=que.top();
      que.pop();
      int tt=min(y,x/2);
      ret+=tt;
      x-=tt*2,y-=tt;
      if(y)que.push(y);
      if(x)que.push(x);
   }
   ret+=que.size()/3;
   printf("%d\n",ret);
    return 0;
}
