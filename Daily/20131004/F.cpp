#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char str1[5],str2[5];
int ans[10][10];
int ret;
int tans[10][10];
int ttans[10][10];


int di[7][4][2] {
    {{0,1},{0,1},{0,1},{0,0}},
    {{-1,0},{0,1},{0,1},{0,0}},
    {{0,1},{1,0},{-1,0},{0,1}},
    {{0,1},{0,1},{1,0},{0,0}},
    {{0,1},{1,0},{0,1},{0,0}},
    {{-1,0},{0,1},{1,0},{0,0}},
    {{0,1},{-1,0},{0,1},{0,0}},
};
int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
int dir[7][4][4][2];
void init_1() {
    for(int i=0; i<7; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<2; k++)
                dir[i][0][j][k]=di[i][j][k];
    for(int t=0; t<3; t++)
        for(int i=0; i<7; i++)
            for(int j=0; j<4; j++) {
                int pos=-1;
                for(int k=0; k<4; k++)
                    if(dir[i][t][j][0]==next[k][0]&&dir[i][t][j][1]==next[k][1]) {
                        pos=k;
                        break;
                    }
                if(pos!=-1) {
                    pos=(pos+1)%4;
                    dir[i][t+1][j][0]=next[pos][0];
                    dir[i][t+1][j][1]=next[pos][1];
                } else {
                    dir[i][t+1][j][0]=dir[i][t][j][0];
                    dir[i][t+1][j][1]=dir[i][t][j][1];
                }
            }
}

void pd() {
    if(ret==-1) {
        for(int i=0; i<6; i++)
            for(int j=0; j<6; j++)
                ans[i][j]=tans[i][j];
        ret=1;
    } else {
        int sign=0;
        for(int i=0; i<6; i++)
            for(int j=0; j<6; j++) {
                if(tans[i][j]&&!ans[i][j]) {
                    sign=1;

                    for(int ii=0; ii<6; ii++)
                        for(int jj=0; jj<6; jj++)
                            ans[ii][jj]=tans[ii][jj];

                    return;
                } else if(!tans[i][j]&&ans[i][j]) {
                    return;
                }
            }
        if(sign) {
            for(int i=0; i<6; i++)
                for(int j=0; j<6; j++)
                    ans[i][j]=tans[i][j];
        }
    }
}

inline bool fill_1(int id,int c,int x,int y,bool sign,int val,int fuck) {

    if(fuck) {
        int tx=x,ty=y;
        if(sign) {
            ttans[x][y]=1;
            for(int i=0; i<4; i++) {

                x+=dir[id][c][i][0];
                y+=dir[id][c][i][1];
                ttans[x][y]=1;
            }
            return 1;
        }

        if(x<0||x>=6||y<0||y>=6)return 0;
        if(ttans[x][y]==2||ttans[x][y]==0)return 0;
        for(int i=0; i<4; i++) {

            x+=dir[id][c][i][0];
            y+=dir[id][c][i][1];

            if(x<0||x>=6||y<0||y>=6)return 0;
            if(ttans[x][y]==2||ttans[x][y]==0)return 0;
        }
        x=tx,y=ty;

        ttans[x][y]=2;
        for(int i=0; i<4; i++) {

            x+=dir[id][c][i][0];
            y+=dir[id][c][i][1];

            ttans[x][y]=2;
        }
        return 1;
    }

    int tx=x,ty=y;
    if(sign) {
        tans[x][y]=0;
        for(int i=0; i<4; i++) {

            x+=dir[id][c][i][0];
            y+=dir[id][c][i][1];
            tans[x][y]=0;
        }

        return 1;
    }

    if(x<0||x>=6||y<0||y>=6)return 0;
    if(tans[x][y])return 0;
    for(int i=0; i<4; i++) {

        x+=dir[id][c][i][0];
        y+=dir[id][c][i][1];

        if(x<0||x>=6||y<0||y>=6)return 0;
        if(tans[x][y])return 0;
    }
    x=tx,y=ty;

    tans[x][y]=1;
    for(int i=0; i<4; i++) {

        x+=dir[id][c][i][0];
        y+=dir[id][c][i][1];

        tans[x][y]=1;
    }
    return 1;
}

bool dfs_2(int cnt) {
    if(cnt==3)return true;
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            if(tans[i][j]==1) {
                int cur=str2[cnt]-'A';
                for(int k=0; k<4; k++) {
                    if(fill_1(cur,k,i,j,0,2,1)) {
                        if(dfs_2(cnt+1))return true;
                        fill_1(cur,k,i,j,1,1,1);
                    }
                }
            }
}

bool cmp()
{
    for(int i=0;i<6;i++)
      for(int j=0;j<6;j++)
      {
          if(ans[i][j]&&!tans[i][j])return 1;
          if(tans[i][j]&&!ans[i][j])return 0;
      }
      return 0;
}

bool yes=0;
void dfs_1(int cnt) {
    //if(yes)return;



    if(cnt==3) {
        for(int i=0; i<6; i++)
            for(int j=0; j<6; j++)
                ttans[i][j]=tans[i][j];

         if(ret!=-1&&cmp())return;

        yes=1;

        /*for(int i=0; i<6; i++) {
               for(int j=0; j<6; j++) {
                   if(tans[i][j])printf("#");
                   else printf(".");
               }
               printf("\n");
           }*/




        if(dfs_2(0))pd();
        return;
    }
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            if(tans[i][j]==0) {
                int cur=str1[cnt]-'A';
                for(int k=0; k<4; k++) {
                    if(fill_1(cur,k,i,j,0,1,0)) {
                        dfs_1(cnt+1);
                        fill_1(cur,k,i,j,1,0,0);
                    }
                }
            }
}

int main() {
    //freopen("f.in.cpp","r",stdin);
    init_1();


    //for(int i=0;i<4;i++)
    // printf("%d %d\n",dir[3][3][i][0],dir[3][3][i][1]);


    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++) {
        scanf("%s%s",str1,str2);
        ret=-1;
        memset(tans,0,sizeof(tans));
        dfs_1(0);
        printf("%d\n",t);
        if(ret==-1)printf("No solution\n");
        else {
            for(int i=0; i<6; i++) {
                for(int j=0; j<6; j++) {
                    if(ans[i][j])printf("#");
                    else printf(".");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
