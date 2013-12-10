#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 20
struct Point
{
    int x,y;
    Point(){}
    Point(int a,int b){
        x=a;y=b;
    }
};
queue<Point> q;
char str[N][N];
int get[N][N];
int pos[30][2];
int n,ans;
int a[4][2]={-1,0,0,-1,1,0,0,1};
void bfs(char A,char B,int s1,int s2)
{
    while(!q.empty()) q.pop();
    memset(get,-1,sizeof(get));
    get[s1][s2]=0;
    q.push(Point(s1,s2));
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        int x=p.x,y=p.y;
        for(int i=0;i<4;i++){
            int j=x+a[i][0],k=y+a[i][1];
            if(j<0||j>=n||k<0||k>=n) continue;
            if(get[j][k]!=-1||str[j][k]=='#'||str[j][k]>B) continue;
            get[j][k]=get[x][y]+1;
            if(str[j][k]==B){
                ans+=get[j][k];
                return;
            }
            q.push(Point(j,k));
        }
    }
    ans=-1;

}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
        }

        int cnt=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(str[i][j]>='A'&&str[i][j]<='Z'){
            pos[str[i][j]-'A'][0]=i;
            pos[str[i][j]-'A'][1]=j;
            cnt++;
        }
        ans=0;
        for(i=1;i<cnt;i++){
             bfs('A'+i-1,'A'+i,pos[i-1][0],pos[i-1][1]);
             if(ans==-1) break;
        }
        if(ans==-1) puts("Impossible");
        else printf("%d\n",ans);


    }
    return 0;

}
