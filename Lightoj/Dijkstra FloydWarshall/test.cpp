#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int M = 1005, inf = 1 << 30;
#define cc(m,v) memset(m,v,sizeof(m))

struct {
    int v, len, next;
} edge[10 * M];
int dis[M][2], cnt[M][2], vis[M][2];
int head[M], k;

struct node {
    int v, flag;

    node(int vv, int f) {
        v = vv, flag = f;
    }
    bool operator<(const node & a) const {
        return dis[v][flag] > dis[a.v][a.flag];
    }
};
priority_queue<node>q;

void addedge(int u, int v, int len) {
    edge[k].v = v, edge[k].len = len, edge[k].next = head[u], head[u] = k++;
}

void dijkstra(int s, int n) {
    int i, v, len;
    cc(cnt, 0), cc(vis, 0);
    for (i = 0; i <= n; i++)
        dis[i][0] = dis[i][1] = inf;
    cnt[s][0] = 1;
    dis[s][0] = 0;
    q.push(node(s, 0));
    while (!q.empty()) {
        node u = q.top();
        q.pop();
        if (vis[u.v][u.flag]) continue;
        vis[u.v][u.flag] = 1;
        for (i = head[u.v]; i != -1; i = edge[i].next) {
            v = edge[i].v, len = dis[u.v][u.flag] + edge[i].len;
            if (len < dis[v][0]) {
                if (dis[v][0] != inf) {
                    dis[v][1] = dis[v][0], cnt[v][1] = cnt[v][0];
                    q.push(node(v, 1));
                }
                dis[v][0] = len, cnt[v][0] = cnt[u.v][u.flag];
                q.push(node(v, 0));
            } else if (len == dis[v][0]) cnt[v][0] += cnt[u.v][u.flag];
            else if (len < dis[v][1]) {
                dis[v][1] = len, cnt[v][1] = cnt[u.v][u.flag];
                q.push(node(v, 1));
            } else if (len == dis[v][1]) cnt[v][1] += cnt[u.v][u.flag];
        }
    }
}

void ainit() {
    k = 0, cc(head, -1);
}

int main(int argc, char** argv) {

    int cas, m, n, s, t, i, j, ans;
    int a, b, c;
    scanf("%d", &cas);
    while (cas--) {
        ainit();
        scanf("%d%d", &n, &m);
        for (i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
        }
        scanf("%d%d", &s, &t);
        dijkstra(s, n);
        ans = cnt[t][0];
        if (dis[t][0] == dis[t][1] - 1) ans += cnt[t][1];
        printf("%d\n", ans);
    }
    return 0;
}
