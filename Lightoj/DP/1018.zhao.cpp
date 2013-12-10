#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20;
const int MAXMASK = 1 << 16;

int n, w, k;
struct pnt{
    int x, y;
}   p[MAXN];
bool l[MAXN][MAXN][MAXN];
int f[MAXMASK];

inline bool line(int a, int b, int c){
    return (p[a].x - p[b].x) * (p[a].y - p[c].y) == (p[a].x - p[c].x) * (p[a].y - p[b].y);
}

int dp(int x){
    int& s = f[x];
    //printf("%d %d\n", x, s);
    if (s >= 0) return s;
    s = n;
    for (int i = 0;i < n;i++)
        if ((1 << i) & x){
            for (int j = i + 1;j < n;j++)
                if ((1 << j) & x){
                    int nx = (1 << i) | (1 << j);
                    for (int k = j + 1;k < n;k++)
                        if ((1 << k) & x){
                            nx |= (l[i][j][k] << k);
                        }
                    //printf("x, nx = %d, %d\n", x, nx);
                    s = min(s, dp(x ^ nx) + 1);
                }
            break;
        }
    if (s == n) s = 1;
    return s;
}

int main(){

    freopen("in.cpp", "r", stdin);
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 0;i < n;i++){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                for (int k = 0;k < n;k++)
                    l[i][j][k] = line(i, j, k);
        memset(f, -1, sizeof(f));
        f[0] = 0;
        printf("Case %d: %d\n", ++t, dp((1 << n)- 1));
    }
    return 0;
}
