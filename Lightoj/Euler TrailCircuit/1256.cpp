#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define N 30
int e[N][N];
int in[N],ans[1005];
bool get[1005];
char s[1005][25];
int begin,cnt,n;
bool check()
{
    int j=0,k=0;
    for(int i=0;i<26;i++)
    {
        if(in[i]<-1||in[i]>1) return false;
        else if(in[i]==-1) {j++; begin=i;}
        else if(in[i]==1) k++;
    }
    if(j==0&&k==0) return true;
    if(j==1&&k==1) return true;
    return false;
}
void euler(int u)
{
    for(int v=0;v<26;v++)
    if(e[u][v]>0)
    {
        e[u][v]--;
        euler(v);
    }
   ans[cnt++]=u;
}
void find(int a,int b,int flag)
{
   for(int i=0;i<n;i++)
   {
       if(get[i]) continue;
       int k=strlen(s[i]);
       if(s[i][0]-'a'==a&&s[i][k-1]-'a'==b)
       {
           printf("%s",s[i]);
           get[i]=true;
           if(flag==0) puts("");
           else printf(" ");
           return;
       }
   }
}
int main()
{

   //freopen("in.cpp","r",stdin);

    int T,i,j,k,t,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);
        cnt=0;
        memset(e,0,sizeof(e));
        memset(in,0,sizeof(in));
        memset(get,false,sizeof(get));

        scanf("%d",&n);
        for(t=0;t<n;t++)
        {
            scanf("%s",s[t]);
            k=strlen(s[t]);
            i=s[t][0]-'a'; j=s[t][k-1]-'a';
            e[i][j]++;
            begin=i;
            in[j]++;
            in[i]--;

        }
        if(!check())
        {
            puts("No");
            continue;
        }
        euler(begin);
        if(cnt!=n+1)
        {
            puts("No");
            continue;
        }
        puts("Yes");
       for(i=cnt-1;i>0;i--)
       find(ans[i],ans[i-1],i-1);

    }
    return 0;
}

