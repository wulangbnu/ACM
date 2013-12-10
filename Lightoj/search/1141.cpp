#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1000+5
int p[N],cnt;
bool f[N];
queue<int> q;
int d[N];
void init()
{
    f[0]=f[1]=true;
    for(int i=2;i<N;i++)
    if(!f[i]){
        p[cnt++]=i;
        for(int j=i*i;j<N;j+=i)
        f[j]=true;
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);
    init();
    int T,s,t,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&s,&t);

        memset(d,-1,sizeof(d));
        while(!q.empty()) q.pop();
        d[s]=0;
        q.push(s);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(i=cnt-1;i>=0;i--)
            if(x%p[i]==0&&x!=p[i]&&x+p[i]<=t&&d[x+p[i]]==-1){
                d[x+p[i]]=d[x]+1;
                if(x+p[i]==t) break;
                q.push(x+p[i]);
            }
        }
        printf("%d\n",d[t]);
    }
    return 0;
}
