#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int n;
int g[MAXN];
double f[MAXN];

int main(){
    freopen("in.cpp", "r", stdin);
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 0;i < n;i++) scanf("%d", &g[i]);
        memset(f, 0, sizeof(f));
        for (int i = n - 1;i >= 0;i--){
            f[i] += g[i];
            int cnt = min(n - 1, i + 6) - i;
            for (int j = i + 1;j <= i + cnt;j++) f[i] += f[j] * 1.0 / cnt;
        }
        printf("Case %d: %.8f\n", ++t, f[0]);
    }
    return 0;
}
