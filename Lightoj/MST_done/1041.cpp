#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
#define M 55
#define N 105
map<string,int> mp;
int pre[N];
char str1[50],str2[50];
string s1,s2;
struct Edge
{
    int a,b,v;
    bool operator <(const Edge tt) const
    {
        return v<tt.v;
    }
}e[M];
int find(int v)
{
    return pre[v]==v?v:pre[v]=find(pre[v]);
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,n,m,i,j,k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);

        mp.clear();
        scanf("%d",&m);


        n=0;
        for(i=0;i<m;i++)
        {
           scanf("%s %s %d",str1,str2,&j);
           s1=str1,s2=str2;
           if(mp.count(s1)==0) mp[s1]=n++;
           if(mp.count(s2)==0) mp[s2]=n++;
           e[i].a=mp[s1];
           e[i].b=mp[s2];
           e[i].v=j;
        }

       // for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
       // printf("%s  %d\n",it->first.c_str(),it->second);

        sort(e,e+m);

        int ans=0;
        for(i=0;i<=n;i++) pre[i]=i;
        for(i=j=0;i<m;i++)
        {
            int v1=find(e[i].a),v2=find(e[i].b);
            if(v1!=v2)
            {


                pre[v1]=v2;
                ans+=e[i].v;
                j++;

            }
            if(j>=n-1) break;
        }
        if(j<n-1) puts("Impossible");
        else printf("%d\n",ans);
    }

    return 0;
}



