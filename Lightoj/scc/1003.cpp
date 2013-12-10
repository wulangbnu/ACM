#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<string>
using namespace std;
#define M 10005
int in[M];
int u[M],v[M],first[M],next[M];
queue<int> q;
map<string,int> mp;
char str1[15],str2[15];
string s1,s2;
int main()
{
    int T,m,i,j,k,n;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
       printf("Case %d: ",cas++);
       memset(in,0,sizeof(in));
       mp.clear();
       while(!q.empty()) q.pop();
       n=0;
       memset(first,-1,sizeof(first));

       scanf("%d",&m);
       for(i=0;i<m;i++)
       {
          scanf("%s %s",str1,str2);
          s1=str1; s2=str2;
          if(mp.count(s1)==0) mp[s1]=n++;
          if(mp.count(s2)==0) mp[s2]=n++;
          j=mp[s1], k=mp[s2];
          u[i]=j, v[i]=k;
          next[i]=first[j];
          first[j]=i;
          in[k]++;
        }
        for(i=0;i<n;i++)
        if(in[i]==0) q.push(i);
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            n--;
            for(int e=first[i];e+1;e=next[e])
            {
                in[v[e]]--;
                if(in[v[e]]==0) q.push(v[e]);
            }
        }
        if(n) puts("No");
        else puts("Yes");


    }
    return 0;
}
