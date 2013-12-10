#include<iostream>
using namespace std;
const int N=21000*2;//一共有2*n个点
const int M=41000*2;//存正向边和反向边，注意乘以2
struct edge{
    int to,ne;
}e[M];

int g[N],g1[N],topo[N],f[N],SCC_root[N],c[N];
int N,M,cp,f_time,SCC_n;

void add_edge(int A,int B){
    e[cp].to=B;e[cp].ne=g[A];g[A]=cp++;
    e[cp].to=A;e[cp].ne=g1[B];g1[B]=cp++;
}
void init(){
    int i,A,B;
    freopen("spo.in","r",stdin);
    freopen("spo.out","w",stdout);
    scanf("%d%d",&N,&M);
    memset(g,0,sizeof(g));
    memset(g1,0,sizeof(g1));
    cp=1;
    for(i=0;i<M;i++){
        scanf("%d%d",&A,&B);
        if (A%2) A = (A+1)/2; else A = (A+1)/2 + N;
        if (B%2) B = (B+1)/2; else B = (B+1)/2 + N;
        int aa ,bb;
        if (A>N) aa = A - N; else aa = A + N;
        if (B>N) bb = B - N; else bb = B + N;
        add_edge(A, bb);
        add_edge(B, aa);
    }
}
void dfs1(int u){
	f[u]=1;
	for(int i=g[u];i;i=e[i].ne)
		if(f[e[i].to]==0) dfs1(e[i].to);
	topo[++f_time]=u;
}
void dfs2(int u){
	f[u]=SCC_n;
	for(int i=g1[u];i;i=e[i].ne)
		if(f[e[i].to]==0) dfs2(e[i].to);
}
void Kosaraju(){
	int i;
	memset(f,0,sizeof(f));
	f_time=0;
	for(i=1;i<=2*N;i++) if(f[i]==0) dfs1(i);
	memset(f,0,sizeof(f));
	SCC_n=0;
	for(i=f_time;i>=1;i--) if(f[topo[i]]==0){
		SCC_root[++SCC_n] = topo[i];
        dfs2(topo[i]);
	}
}
bool judge(){
	for(int i=1;i<=N;i++)
		if(f[i]==f[i+N]) return false;
	return true;
}
void color2(int u){
	int i,v;
	c[u]=2;
	for(i=g1[u];v=e[i].to,i;i=e[i].ne)
		if(c[v]==0 && f[u]==f[v]) color2(v);
}
void color1(int u){
	int i,v;
	c[u]=1;
	for(i=g1[u];v=e[i].to,i;i=e[i].ne)
		if(c[v]==0 && f[u]==f[v]) color1(v);
	if (u > N) color2(u-N);
    else color2(u+N);
}
void choose(){
	int i;
	for(i=SCC_n;i>=1;i--)
		if(c[SCC_root[i]]==0) color1(SCC_root[i]);
    for(i=1;i<=N;i++) {
        if(c[i]==1) printf("%d\n",2*i-1);
        if(c[i+N]==1) printf("%d\n",2*i);
    }
}
int main(){
	init();
	Kosaraju();
	if(judge()) choose();else printf("NIE\n");
	return 0;
}
