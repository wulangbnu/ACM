#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int head[20005],n,shead[20005];
int DFN[20005],Low[20005],Stack[20005],Index,top,scc,Belong[20005],ecnt,secnt;
bool Instack[20005],vis[20005];
int link[50005];
struct edge
{
 int u,v,next;
}E[1000000],E1[1000000];
void Insert(int u,int v)
{
 E[ecnt].u=u;
 E[ecnt].v=v;
 E[ecnt].next=head[u];
 head[u]=ecnt++;
}
void SInsert(int u,int v)//缩完点以后再次构图插边
{
 E1[secnt].u=u;
 E1[secnt].v=v;
 E1[secnt].next=shead[u];
 shead[u]=secnt++;
}
bool find(int x)
{
 int i,v;
 for(i=shead[x];i!=-1;i=E1[i].next)
 {
  v=E1[i].v;
  if(!vis[v])
  {
   vis[v]=1;
   if(link[v]==-1||find(link[v]))
   {
    link[v]=x;
    return 1;
   }
  }
 }
 return 0;
}
int MaxMatch()
{
 int i,ans=0;
 memset(link,-1,sizeof(link));
 for(i=1;i<=scc;i++)//注意点是重新构图以后1—scc进行找增广路
 {
  memset(vis,0,sizeof(vis));
  if(find(i))ans++;
 }
 return ans;
}
void Tarjan(int u)
{
    int i,v;
    Low[u]=DFN[u]=++Index;
    Stack[++top]=u;
    Instack[u]=1;
    for(i=head[u];i!=-1;i=E[i].next)
    {
        v=E[i].v;
        if(!DFN[v])
        {
            Tarjan(v);
            if(Low[u]>Low[v])
                Low[u]=Low[v];
        }
        else if(Instack[v]&&Low[u]>DFN[v])
            Low[u]=DFN[v];
    }
    if(Low[u]==DFN[u])
    {
        scc++;
        do{
            v=Stack[top--];
            Instack[v]=0;
            Belong[v]=scc;
        }while(u!=v);
    }
    return;
}

void Init()
{
 int i,u,v,m;
 ecnt=0;
 secnt=0;
 memset(shead,-1,sizeof(shead));
 memset(head,-1,sizeof(head));
 scanf("%d%d",&n,&m);
 for(i=1;i<=m;i++)
 {
  scanf("%d%d",&u,&v);
  Insert(u,v);
 }
}
void Solve()
{
 int i,v,u;
 scc=top=Index=0;
 memset(DFN,0,sizeof(DFN));
 memset(Low,0,sizeof(Low));
 memset(Instack,0,sizeof(Instack));
 for(i=1;i<=n;i++)
 {
  if(!DFN[i])Tarjan(i);
 }
 //for(i=1;i<=n;i++)
 // printf("~%d ",Belong[i]);
// printf("\n");
 for(i=0;i<ecnt;i++)
 {
  u=E[i].u;
  v=E[i].v;
  if(Belong[u]!=Belong[v])
  {
   SInsert(Belong[u],Belong[v]);
   //printf("!! %d %d\n",Belong[u],Belong[v]);
  }
 }
 int sum=MaxMatch();
  printf("%d\n",scc-sum);


}
int main()
{
    //freopen("in.cpp","r",stdin);
 int cas;
 int wu=1;
  scanf("%d",&cas);
  while(cas--)
  {
      printf("Case %d: ",wu++);
   Init();
   Solve();
  }
 return 0;
}
