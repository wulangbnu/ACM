#include<cstdio>
#include<cstring>
#define N 1005
#define INF 0x7ffffff
int n, ans, cnt, e[N][N];
int pre[N], s[N], top, mark[N], begin, id[N], mincost[N];
bool u[N];
void combine(int root)
{
	int i, j, col;
	col = id[s[begin]];
	for(i = begin; i < top; ++i) {
		id[s[i]] = col;
		ans += mincost[s[i]];
		for(j = 1; j <= n; ++j) {
			if(e[j][s[i]] < INF && e[j][s[i]] - mincost[s[i]] < e[j][col])
				e[j][col] = e[j][s[i]] - mincost[s[i]];
			if(e[s[i]][j] < e[col][j])
				e[col][j] = e[s[i]][j];
		}
	}
	for(i = 1; i <= n; ++i) {
		if(i != root && id[pre[i]] == col)
			pre[i] = col;
	}
	mincost[col] = INF;
	for(i = 1; i <= n; ++i) {
		if(i != col && id[i] == i && e[i][col] < mincost[col]) {//i != colÊÇ¹Ø¼ü
			mincost[col] = e[i][col];
			pre[col] = i;
		}
	}
}
bool findcircle(int root)
{
	int i, tmp;
	memset(u, false, sizeof(u));
	for(i = n; i >= 1; --i) {
		if(i == root || id[i] != i || u[i])
			continue;
		tmp = i;
		top = 0;
		memset(mark, -1, sizeof(mark));
		while(tmp != root && mark[tmp] == -1 && !u[tmp]) {
			u[tmp] = true;
			mark[tmp] = top;
			s[top++] = tmp;
			tmp = pre[tmp];
		}
		if(mark[tmp] != -1) {
			begin = mark[tmp];
			return true;
		}
	}
	return false;
}

void zhuliu(int root)
{
	int i, j;
	for(i = 1; i <= n; ++i) {
		id[i] = i;
		if(i == root)	continue;
		mincost[i] = INF;
		for(j = 1; j <= n; ++j)
			if(i != j && e[j][i] < mincost[i]) {
				mincost[i] = e[j][i];
				pre[i] = j;
			}

	}
	while(findcircle(root))
		combine(root);
	for(i = 1; i <= n; ++i) {
		if(i != root && id[i] == i)
			ans += mincost[i];
	}
}

void dfs(int x)
{
	int i;
	u[x] = true;
	++cnt;
	for(i = 1; i <= n; ++i) {
		if(!u[i] && e[x][i] < INF)
			dfs(i);
	}
}

int main()
{
    //freopen("in.cpp","r",stdin);
	 int T,m, i, j,k, f, t, d,root;
	 int cas=1;
    scanf("%d", &T);
	 while(T--)
	 {
	     printf("Case %d: ",cas++);
		scanf("%d %d %d", &n, &m,&root);
		root++;
		for(i = 1; i <= n; ++i)
			for(j = i; j <= n; ++j)
				e[i][j] = e[j][i] = INF;
		for(i = 0; i < m; i++)
		{
			scanf("%d%d%d", &f, &t, &d);
			++f;
			++t;
			e[f][t] = d;
		}
		cnt = 0;
		memset(u, false, sizeof(u));
		dfs(root);
		if(cnt != n) puts("impossible");
		else {
			ans = 0;
			zhuliu(root);
			printf("%d\n",ans);
		}
	}
	return 0;
}
