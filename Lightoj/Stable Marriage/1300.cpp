#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 205
int a[N][N],f[N];
bool single[N];
int check(int n)
{
    for(int i=1;i<=n;i++)
    if(single[i]&&f[i]<n+1) return i;
    return -1;
}
int main()
{
   int T,n,i,j,k;
   int cas=1;
   scanf("%d",&T);
   while(T--)
   {
       printf("Case %d:",cas++);
       scanf("%d",&n);
       for(i=1;i<=2*n;i++)
       for(j=1;j<=n;j++)
       scanf("%d",&a[i][j]);

       for(i=1;i<=2*n;i++)
       {
          if(i<=n) f[i]=1;
          else f[i]=-1;
          single[i]=true;
       }
       while(1)
       {
           i=check(n);
           if(i==-1) break;
           j=a[i][f[i]];
          if(f[j]==-1)
          {
              single[i]=false;
              f[j]=i;
          }
          else
          {
             for(k=1;k<=n;k++)
             {
                if(a[j][k]==i||a[j][k]==f[j]) break;
             }
             if(a[j][k]==i)
             {
                 single[f[j]]=true;
                 f[f[j]]++;
                 single[i]=false;
                 f[j]=i;
             }
             else f[i]++;
          }
       }

      for(i=n+1;i<=2*n;i++)
      printf(" (%d %d)",f[i],i);
      puts("");
   }
   return 0;
}
