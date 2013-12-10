#include<cstdio>
#include<cstring>
#define N 25
char g[N][N];
int get[N][N];
int ans,n,m;
void dfs(int i,int j)
{
   if(get[i][j]) return;
   get[i][j]=1;
   ans++;
   if(i-1>=0&&!get[i-1][j]&&g[i-1][j]=='.') dfs(i-1,j);
   if(j-1>=0&&!get[i][j-1]&&g[i][j-1]=='.') dfs(i,j-1);
   if(i+1<n&&!get[i+1][j]&&g[i+1][j]=='.')  dfs(i+1,j);
   if(j+1<m&&!get[i][j+1]&&g[i][j+1]=='.')  dfs(i,j+1);


}
int main()
{

    //freopen("in.cpp","r",stdin);
    int T,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        memset(get,0,sizeof(get));
        ans=0;
        scanf("%d %d ",&m,&n);
        for(i=0;i<n;i++)
        scanf("%s",g[i]);

        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(g[i][j]=='@') dfs(i,j);

        printf("%d\n",ans);
    }
}
