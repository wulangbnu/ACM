#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN = 100005;

const int BLK[][4] = {{0, 1, 2, 3},
                      {0, 1, 2, 4},
                      {0, 1, 2, 5},
                      {0, 1, 2, 6},
                      {0, 1, 5, 6},
                      {0, 1, 4, 5},
                      {1, 2, 4, 5}};

vector<ll> v[10];

void rot(int t[4][4]){
    int r[4][4];
    for (int i = 0;i < 4;i++){
        for (int j = 0;j < 4;j++){
            r[i][j] = t[i][j];
        }
    }
    for (int i = 0;i < 4;i++){
        for (int j = 0;j < 4;j++){
            t[j][3 - i] = r[i][j];
        }
    }
}

int cb(ll x){
    int s = 0;
    for (;x;x&=(x-1)) s++;
    return s;
}

void prep(){
    for (int i = 0;i < 7;i++){
        v[i].clear();
        int t[4][4];
        for (int j = 0;j < 4;j++){
            for (int k = 0;k < 4;k++){
                t[j][k] = 0;
            }
        }
        for (int j = 0;j < 4;j++){
            int x = BLK[i][j];
            t[x >> 2][x & 3] = 1;
        }
        for (int r = 0;r < 4;r++){
            for (int j = 5;j <= 15;j++){
                for (int k = 5;k <= 15;k++){
                    ll msk = 0;
                    for (int p = 10;p <= 15;p++){
                        for (int q = 10;q <= 15;q++){
                            int dx = p - j, dy = q - k;
                            if (0 <= dx && dx < 4 && 0 <= dy && dy < 4){
                                if (t[dx][dy]) msk |= 1ll << (35 - ((p - 10) * 6 + q - 10));
                            }
                        }
                    }
                    if (cb(msk) == 4){
                        v[i].push_back(msk);
                    }
                }
            }
            rot(t);
        }
        sort(v[i].begin(), v[i].end());
        v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
//        printf("%d\n", v[i].size());
    }
}

char a[5], b[5];
void init(){
    scanf("%s%s", a, b);
}

set<ll> st;

void pt(ll x){
    for (int i = 0;i < 36;i++){
        if ((1ll << (35 - i)) & x) printf("#");
        else printf(".");
        if (i % 6 == 5) printf("\n");
    }
}

void dfsa(int x, ll y){
    if (x >= 3){
        st.insert(y);
        return;
    }
    int t = a[x] - 'A';
    for (int i = 0;i < (int)v[t].size();i++){
        if (y & v[t][i]) continue;
        dfsa(x + 1, y | v[t][i]);
    }
}

//bool flag;
ll ans;
void dfsb(int x, ll y){
//    if (flag) return;
    if (x >= 3){
        if (st.count(y)){
            ans = max(ans, y);
//            flag = true;
        }
        return;
    }
    int t = b[x] - 'A';
    for (int i = 0;i < (int)v[t].size();i++){
        if (y & v[t][i]) continue;
        dfsb(x + 1, y | v[t][i]);
    }
}

void work(){
    st.clear();
    dfsa(0, 0);
//    flag = false;
    ans = -1;
    dfsb(0, 0);
    if (ans < 0) printf("No solution\n");
    else pt(ans);
}

int main(){

    freopen("f.in", "r", stdin);

    prep();
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        init();
        printf("%d\n", ++t);
        work();
    }
    return 0;
}
