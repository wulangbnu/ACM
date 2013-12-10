/**
查询区间不相交线段数的最大值 路径压缩
Problem Description
    There are N intervals in number axis, and M queries just like “QUERY(a,b)” indicate asking the maximum number of the disjoint intervals between (a,b) .
Input
    There are several test cases. For each test case, the first line contains two integers N, M (0<N, M<=100000) as described above. In each following N lines, there are two integers indicate two endpoints of the i-th interval. Then come M lines and each line contains two integers indicating the endpoints of the i-th query.You can assume the left-endpoint is strictly less than the right-endpoint in each given interval and query and all these endpoints are between 0 and 1,000,000,000.
Output
    For each query, you need to output the maximum number of the disjoint intervals in the asked interval in one line.
**/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100000+10
int a[4*N],cnt;
struct Point {
    int x,y;
    void input() {
        scanf("%d%d",&x,&y);
    }
    bool operator <(const Point tt) const {
        if(y!=tt.y) return y<tt.y;
        return x>tt.x;
    }
} p[N],query[N],s[N];
int dp[4*N][23];
int find(int x) {
    return lower_bound(a,a+cnt,x)-a;
}
int main() {
    //freopen("in.cpp","r",stdin);

    int n,m,i,j,k;
    while(scanf("%d%d",&n,&m)+1) {

        cnt=0;
        int num=0;
        for(i=0; i<n; i++) s[i].input();
        sort(s,s+n);
        i=0;
        while(i<n) {
            p[num++]=s[i];
            j=i+1;
            while(j<n&&s[j].x<=s[i].x) j++;
            i=j;

        }


        for(i=0; i<num; i++) {
            a[cnt++]=p[i].x;
            a[cnt++]=p[i].y;
        }
        for(i=0; i<m; i++) {
            query[i].input();
            a[cnt++]=query[i].x;
            a[cnt++]=query[i].y;
        }
        sort(a,a+cnt);
        cnt=unique(a,a+cnt)-a;
        for(i=0; i<num; i++) {
            p[i].x=find(p[i].x);
            p[i].y=find(p[i].y);
        }
        for(i=0; i<m; i++) {
            query[i].x=find(query[i].x);
            query[i].y=find(query[i].y);
        }


        memset(dp,0x7f,sizeof(dp));
        int INF=dp[0][0];
        for(j=i=0; i<num; i++) {
            while(j<cnt&&j<=p[i].x) dp[j++][0]=p[i].y;
        }

        for(j=1; j<23; j++)
            for(i=0; i<cnt; i++) {
                dp[i][j]=dp[i][j-1]==INF?INF:dp[dp[i][j-1]][j-1];
            }
        for(i=0; i<m; i++) {
            int ans=0,x=query[i].x,y=query[i].y;
            for(j=22; j>=0; j--)
                if(dp[x][j]<=y) {
                    ans+=(1<<j);
                    x=dp[x][j];
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}
