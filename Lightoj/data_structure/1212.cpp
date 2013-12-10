#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
using namespace std;
deque<int> q;
void init()
{
    while(!q.empty()) q.pop_back();
}
char str[50];
int main()
{
    //freopen("in.cpp","r",stdin);

   int T,cas=1,n,m,i,j,k;
   scanf("%d",&T);
   while(T--){
        init();
        printf("Case %d:\n",cas++);
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%s",str);
            if(strcmp(str,"pushLeft")==0){
                scanf("%d",&k);
                if(q.size()==n) puts("The queue is full");
                else{
                    q.push_front(k);
                    printf("Pushed in left: %d\n",k);
                }
            }
            else if(strcmp(str,"pushRight")==0){
                scanf("%d",&k);
                if(q.size()==n) puts("The queue is full");
                else{
                    q.push_back(k);
                    printf("Pushed in right: %d\n",k);
                }
            }
            else if(strcmp(str,"popLeft")==0){
                if(q.empty()) puts("The queue is empty");
                else {
                    printf("Popped from left: %d\n",q.front());
                    q.pop_front();
                }
            }
            else if(strcmp(str,"popRight")==0){
                if(q.empty()) puts("The queue is empty");
                else {
                    printf("Popped from right: %d\n",q.back());
                    q.pop_back();
                }
            }
        }
   }
   return 0;
}
