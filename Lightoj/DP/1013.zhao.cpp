#include <cstdio>
#include <cstring>
const int N = 35;
char s[2][N];
int l1, l2;
int f[N][N];
long long g[N][N];

void update(int &x, int nx, long long& y, long long ny){
    if (x > nx){
        x = nx;
        y = ny;
    }
    else if (x == nx){
        y += ny;
    }
}
int main(){
    freopen("in.cpp", "r", stdin);
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%s%s", s[0], s[1]);
        l1 = strlen(s[0]);
        l2 = strlen(s[1]);
        memset(f, 63, sizeof(f));
        memset(g, 0, sizeof(g));
        f[0][0] = 0;
        g[0][0] = 1;
        for (int i = 0;i <= l1;i++)
        for (int j = 0;j <= l2;j++){
            if (s[0][i] == s[1][j] && i < l1 && j < l2){
                update(f[i + 1][j + 1], f[i][j] + 1, g[i + 1][j + 1], g[i][j]);
            }
            else{
                    if (i < l1) update(f[i + 1][j], f[i][j] + 1, g[i + 1][j], g[i][j]);
                    if (j < l2) update(f[i][j + 1], f[i][j] + 1, g[i][j + 1], g[i][j]);
            }
        }
        printf("Case %d: %d %lld\n", ++t, f[l1][l2], g[l1][l2]);
    }
    return 0;
}
