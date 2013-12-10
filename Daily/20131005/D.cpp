#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=1005;

char s[maxn];
int f[10][9],n,pnt[10][9][2];
int g[10][9];
int c[10];
bool yes;

int ans[maxn],ret;
int tans[maxn];

void pd(int cnt) {
    if(ret>cnt)return;
    if(ret<cnt) {
        for(int i=1; i<=cnt; i++)
            ans[i]=tans[i];
        ret=cnt;
        return;
    }
    int sign=0;
    for(int i=1; i<=cnt; i++) {
        if(ans[i]>tans[i])return;
        else if(ans[i]<tans[i]) {
            sign=1;
            break;
        }
    }
    if(!sign)return;
    for(int i=1; i<=cnt; i++)
        ans[i]=tans[i];
}

void simple(int a[],int &cnt) {
    bool sign=0;
    int l=1;
    for(int i=1; i<=cnt; i++) {
        if(a[i])sign=1;
        if(!sign&&!a[i])l++;
    }
    if(l>cnt) {
        a[1]=0;
        cnt=1;
    } else {
        for(int i=l; i<=cnt; i++)
            a[i-l+1]=a[i];
        cnt=cnt-l+1;
    }
}

bool dp(int st) {

    //printf("** %d\n",st);

    memset(f,-1,sizeof(f));
    memset(g,0,sizeof(g));
    f[0][st%9]=c[0];
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            if(f[i][j]==-1)continue;
            for(int k=0; k<=c[i+1]; k++) {
                int tt=f[i][j]+k;
                if(f[i+1][(j+k*(i+1))%9]<tt) {
                    f[i+1][(j+k*(i+1))%9]=tt;
                    pnt[i+1][(j+k*(i+1))%9][0]=i;
                    pnt[i+1][(j+k*(i+1))%9][1]=j;
                    g[i+1][j+k*(i+1)%9]=k;
                } else if(f[i+1][(j+k*(i+1))%9]==tt) {
                    if(g[i+1][(j+k*(i+1))%9]<k) {
                        f[i+1][(j+k*(i+1))%9]=tt;
                        pnt[i+1][(j+k*(i+1))%9][0]=i;
                        pnt[i+1][(j+k*(i+1))%9][1]=j;
                        g[i+1][j+k*(i+1)%9]=k;
                    }
                }
            }
        }
    if(f[9][0]==-1)return 0;
    int cnt=0;
    int x=9,y=0;
    while(x>=1) {
        int py=pnt[x][y][1];
        int tt=f[x][y]-f[x-1][py];
        for(int i=1; i<=tt; i++)
            tans[++cnt]=x;
        x--,y=py;
    }
    for(int i=1; i<=f[0][y]; i++)
        tans[++cnt]=0;
    int tmp[3],cnt_tmp=0;
    if(st==0) {
        tmp[1]=tmp[2]=0;
        cnt_tmp=2;
    } else {
        while(st!=0) {
            tmp[++cnt_tmp]=st%10;
            st/=10;
        }
        if(cnt_tmp==1)
            tmp[++cnt_tmp]=0;
    }
    //printf("%d %d\n",tmp[1],tmp[2]);
    for(int i=cnt_tmp; i>=1; i--)
        tans[++cnt]=tmp[i];
    simple(tans,cnt);
    pd(cnt);
    return 1;
}

int main() {
    //freopen("in.cpp","r",stdin);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s);
        memset(c,0,sizeof(c));
        n=strlen(s);
        if(n==1&&s[0]=='0') {
            printf("Case %d: 0\n",++ncase);
            continue;
        }

        yes=0;
        ret=0;
        for(int i=0; i<n; i++)
            c[s[i]-'0']++;

        //   printf("** %d\n",n);

        for(int i=0; i<100; i++) {
            if(i%4)continue;
            //printf("** %d\n",i);
            int tmp[10],cnt_tmp=0;
            if(i==0) {
                tmp[1]=tmp[2]=0;
                cnt_tmp=2;
            } else {
                int st=i;
                while(st!=0) {
                    tmp[++cnt_tmp]=st%10;
                    st/=10;
                }
                if(cnt_tmp==1) {
                    tmp[++cnt_tmp]=0;
                }
            }
            bool sign=0;
            for(int j=1; j<=cnt_tmp; j++) {
                c[tmp[j]]--;
                if(c[tmp[j]]<0) {
                    sign=1;
                }
            }
            for(int j=1; j<=cnt_tmp; j++)
                c[tmp[j]]++;
            if(!sign) {
                for(int j=1; j<=cnt_tmp; j++)
                    c[tmp[j]]--;

                // printf("***\n");

                if(dp(i)) {
                    yes=1;
                }

                for(int j=1; j<=cnt_tmp; j++)
                    c[tmp[j]]++;
            }
        }
        if(!yes)printf("Case %d: impossible\n",++ncase);
        else {
            printf("Case %d: ",++ncase);
            for(int i=1; i<=ret; i++)
                printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}


