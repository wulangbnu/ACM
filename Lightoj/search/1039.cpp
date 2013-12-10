#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
struct Point
{
    char a,b,c;
    bool operator <(const Point tt) const
    {
        if(a!=tt.a) return a<tt.a;
        if(b!=tt.b) return b<tt.b;
        return c<tt.c;
    }
}ss,t,tmp,p;
map<Point,int> mp;
queue<Point> q;
char s[3][26];
char add(char ch)
{
    if(ch+1<='z') return ch+1;
    return 'a';
}
char sub(char ch)
{
    if(ch-1>='a') return ch-1;
    return 'z';
}
int main()
{

    //freopen("in.cpp","r",stdin);

     int  T,n,i,j,k;
     int cas=1;
     scanf("%d",&T);
     while(T--)
     {
         printf("Case %d: ",cas++);
         mp.clear();
         while(!q.empty()) q.pop();
         char str[5];
         scanf("%s",str);
         ss.a=str[0],ss.b=str[1],ss.c=str[2];

         scanf("%s",str);
         t.a=str[0],t.b=str[1],t.c=str[2];
         scanf("%d",&n);
         while(n--)
         {
            scanf("%s %s %s",s[0],s[1],s[2]);
            for(i=0;s[0][i];i++)
            for(j=0;s[1][j];j++)
            for(k=0;s[2][k];k++)
            {
                tmp.a=s[0][i];
                tmp.b=s[1][j];
                tmp.c=s[2][k];
                mp[tmp]=-1;
            }
         }
         if(mp.count(ss)||mp.count(t))
         {
             puts("-1");
             continue;
         }

         mp[ss]=0;
         q.push(ss);
        while(!q.empty()&&mp.count(t)==0)
         {
             p=q.front();
             q.pop();
             i=mp[p];

             tmp=p;
             tmp.a=add(tmp.a);
             if(mp.count(tmp)==0)
             mp[tmp]=i+1,q.push(tmp);

             tmp=p;
             tmp.a=sub(tmp.a);
             if(mp.count(tmp)==0)
             mp[tmp]=i+1,q.push(tmp);

             tmp=p;
             tmp.b=add(tmp.b);
             if(mp.count(tmp)==0)
             mp[tmp]=i+1,q.push(tmp);

             tmp=p;
             tmp.b=sub(tmp.b);
             if(mp.count(tmp)==0)
             mp[tmp]=i+1,q.push(tmp);

             tmp=p;
             tmp.c=add(tmp.c);
             if(mp.count(tmp)==0)
             mp[tmp]=i+1,q.push(tmp);

             tmp=p;
             tmp.c=sub(tmp.c);
             if(mp.count(tmp)==0)
             mp[tmp]=i+1,q.push(tmp);




         }


         if(mp.count(t)==0) puts("-1");
         else printf("%d\n",mp[t]);






     }
     return 0;
}









