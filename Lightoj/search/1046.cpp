#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 12
#define INF 1000000000
struct Point
{
    int x,y;
}p;
queue<Point> q;
char g[N][N];
int step[N*N][N][N];
int a[8]={1,1,2,2,-1,-1,-2,-2};
int b[8]={2,-2,1,-1,2,-2,1,-1};
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k,cnt;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
     memset(step,-1,sizeof(step));
     scanf("%d %d",&n,&m);
     cnt=0;
     for(i=0;i<n;i++)
     scanf("%s",g[i]);
     for(i=0;i<n;i++)
     for(j=0;j<m;j++)
     {
       if(g[i][j]=='.') continue;
       k=g[i][j]-'0';
       step[cnt][i][j]=0;
       p.x=i, p.y=j;
       q.push(p);
       while(!q.empty())
       {
         p=q.front();
         q.pop();
         int x=p.x, y=p.y;
         for(int s=0;s<8;s++)
         {
             if(x+a[s]>n-1||x+a[s]<0||y+b[s]>m-1||y+b[s]<0) continue;
            if(step[cnt][x+a[s]][y+b[s]]!=-1) continue;
            step[cnt][x+a[s]][y+b[s]]=step[cnt][x][y]+1;
            p.x=x+a[s], p.y=y+b[s];
            q.push(p);
         }
       }
       for(int s=0;s<n;s++)
       for(int t=0;t<m;t++)
       if(step[cnt][s][t]!=-1)
       step[cnt][s][t]=(step[cnt][s][t]+k-1)/k;

       cnt++;

     }

     int ans=INF;
     for(i=0;i<n;i++)
     for(j=0;j<m;j++)
     {
         int tmp=0;
        for(k=0;k<cnt;k++)
        {
          if(step[k][i][j]==-1)
          {
              tmp=INF;
              break;
          }
          tmp+=step[k][i][j];
        }

        ans=min(ans,tmp);
     }
     if(ans<INF) printf("%d\n",ans);
     else puts("-1");


    }
    return 0;

}
