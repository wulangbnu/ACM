#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=200+10;
char str[N][N];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m,step[N][N];
struct Point{
    int x,y,z; //z==-1 fire
    Point(){}
    Point(int _x,int _y,int _z){
        x=_x; y=_y; z=_z;
    }
};
queue<Point> q;
bool check(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<m&&str[x][y]!='#');
}
bool isexit(int x,int y){
    return (x==0||x==n-1||y==0||y==m-1);
}
int main(){
    freopen("in.cpp","r",stdin);
    int T,i,j,k,cas=1;
    int s1,s2,t1,t2;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        memset(step,0x3f,sizeof(step));
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
            for(j=0;j<m;j++){
                if(str[i][j]=='J') s1=i,s2=j;
                else if(str[i][j]=='F') t1=i,t2=j;
            }
        }
        while(!q.empty()) q.pop();
        q.push(Point(t1,t2,-1));
        q.push(Point(s1,s2,0));
        step[s1][s2]=0;
        int ans=-1;
        while(!q.empty()){
            Point p=q.front();
            q.pop();
            if(p.z!=-1&&isexit(p.x,p.y)){
                ans=p.z+1;
                break;
            }
            for(i=0;i<4;i++){
                int x=p.x+dx[i],y=p.y+dy[i];
                if(check(x,y)){
                    if(p.z==-1&&str[x][y]!='F'){
                        str[x][y]='F';
                        q.push(Point(x,y,-1));
                    }
                    else if(p.z!=-1&&str[x][y]!='F'&&p.z+1<step[x][y]){
                        step[x][y]=p.z+1;
                        q.push(Point(x,y,step[x][y]));
                    }
                }
            }
        }
        if(ans==-1) puts("IMPOSSIBLE");
        else printf("%d\n",ans);
    }
    return 0;
}
