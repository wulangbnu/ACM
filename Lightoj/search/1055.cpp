#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 12
char g[N][N];
struct Point
{
    int x[3],y[3];
}p;
int x[3],y[3],s[3],t[3];
int step[N][N][N][N][N][N];
int  a[4]={0,0,1,-1};
int  b[4]={1,-1,0,0};
queue<Point> q;
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        memset(step,-1,sizeof(step));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s",g[i]);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(g[i][j]>='A'&&g[i][j]<='C')
        {
            k=g[i][j]-'A';
            p.x[k]=i;
            p.y[k]=j;
        }
        while(!q.empty()) q.pop();
        step[p.x[0]][p.y[0]][p.x[1]][p.y[1]][p.x[2]][p.y[2]]=0;
        q.push(p);
        int flag=0,ans=-1;
        while(!q.empty())
        {
           p=q.front();
           q.pop();
           for(i=0;i<3;i++)
           {
               x[i]=p.x[i];
               y[i]=p.y[i];
           }
           for(i=0;i<4;i++)
           {
              for(j=0;j<3;j++)
              {
                 s[j]=x[j]+a[i];
                 t[j]=y[j]+b[i];
                 if(s[j]>n-1||s[j]<0||t[j]>n-1||t[j]<0||g[s[j]][t[j]]=='#')
                 {
                     s[j]=x[j];
                     t[j]=y[j];
                 }
              }
              if(s[0]==s[1]&&t[0]==t[1])
              {
                  s[0]=x[0]; t[0]=y[0];
                  s[1]=x[1]; t[1]=y[1];
                  if(s[0]==s[2]&&t[0]==t[2])
                  {
                  s[0]=x[0]; t[0]=y[0];
                  s[2]=x[2]; t[2]=y[2];
                  }
                  if(s[1]==s[2]&&t[1]==t[2])
                  {
                  s[1]=x[1]; t[1]=y[1];
                  s[2]=x[2]; t[2]=y[2];
                  }
              }

              else if(s[0]==s[2]&&t[0]==t[2])
              {
                  s[0]=x[0]; t[0]=y[0];
                  s[2]=x[2]; t[2]=y[2];
                  if(s[1]==s[2]&&t[1]==t[2])
                  {
                  s[1]=x[1]; t[1]=y[1];
                  s[2]=x[2]; t[2]=y[2];
                  }
                  if(s[1]==s[0]&&t[1]==t[0])
                  {
                  s[1]=x[1]; t[1]=y[1];
                  s[0]=x[0]; t[0]=y[0];
                  }

              }
              else if(s[1]==s[2]&&t[1]==t[2])
              {
                  s[1]=x[1]; t[1]=y[1];
                  s[2]=x[2]; t[2]=y[2];
                  if(s[1]==s[0]&&t[1]==t[0])
                  {
                  s[1]=x[1]; t[1]=y[1];
                  s[0]=x[0]; t[0]=y[0];
                  }
                  if(s[0]==s[2]&&t[0]==t[2])
                  {
                  s[0]=x[0]; t[0]=y[0];
                  s[2]=x[2]; t[2]=y[2];
                  }
              }
              if(step[s[0]][t[0]][s[1]][t[1]][s[2]][t[2]]!=-1) continue;
              step[s[0]][t[0]][s[1]][t[1]][s[2]][t[2]]=step[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]]+1;
              if(g[s[0]][t[0]]=='X'&&g[s[1]][t[1]]=='X'&&g[s[2]][t[2]]=='X')
              {
                  ans=step[s[0]][t[0]][s[1]][t[1]][s[2]][t[2]];

                  //printf("%d %d %d %d %d %d\n",s[0],t[0],s[1],t[1],s[2],t[2]);
                  flag=1;
                  break;
              }
              for(j=0;j<3;j++)
              {
                  p.x[j]=s[j];
                  p.y[j]=t[j];
              }
              q.push(p);

           }

           if(flag) break;

        }

        if(ans==-1) printf("trapped\n");
        else printf("%d\n",ans);




    }
    return 0;
}











