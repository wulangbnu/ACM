#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=105;

char str[maxn][maxn];
int n,m;

int cal(int x,int y,int x2,int y2)
{
    int ret=0;
    for(int i=x;i<=x2;i++)
      for(int j=y;j<=y2;j++)
        ret+=str[i][j]-'0';
    return ret;
}
void fill(int x,int y,int x2,int y2,int ch)
{
    for(int i=x;i<=x2;i++)
      for(int j=y;j<=y2;j++)
        str[i][j]=ch+'0';
}

void dfs(int x1,int y1,int x2,int y2,int dep)
{
 //  printf("%d %d %d %d\n",x1,y1,x2,y2);


          int all=(x2-x1+1)*(y2-y1+1);
          int cnt=cal(x1,y1,x2,y2);

         // printf("**%d %d\n",all,cnt);


          if(cnt*100>=m*all)
          {
              fill(x1,y1,x2,y2,1);
              return;
          }
          if((all-cnt)*100>=m*all)
          {
              fill(x1,y1,x2,y2,0);
              return;
          }

     int x=(x1+x2)/2,y=(y1+y2)/2;
     dfs(x1,y1,x,y,dep+1);
     dfs(x1,y+1,x,y2,dep+1);
     dfs(x+1,y1,x2,y,dep+1);
     dfs(x+1,y+1,x2,y2,dep+1);
}

int main(){
    //freopen("in.cpp","r",stdin);
    int ncase=0;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        for(int i=0;i<n;i++)scanf("%s",str[i]);
        dfs(0,0,n-1,n-1,0);
        printf("Image %d:\n",++ncase);
        for(int i=0;i<n;i++)
        printf("%s\n",str[i]);
    }
    return 0;
}
