#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100000+10;
int wa[N],wb[N],wv[N],ws[N],sa[N];
char str[N];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(char *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
int *rank=wa,*height=wb;
void calheight(char *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int rmq[N][20];
void RMQ(int n)
{
    for(int i=1;i<=n;i++)
    rmq[i][0]=height[i];
    for(int j=1;(1<<j)<=n+1;j++)
    for(int i=1;i+(1<<j)-1<=n;i++)
    rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
int doit(int i,int j)
{
    i=rank[i],j=rank[j];
    if(i>j) swap(i,j);
    i++;
    int k=log(j-i+1.0)/log(2.0)+(1e-8);
    return min(rmq[i][k],rmq[j-(1<<k)+1][k]);
}
int main()
{
    freopen("in.cpp","r",stdin);

    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        int len=strlen(str);
        str[len]='#';
        scanf("%s",str+len+1);
        n=strlen(str);

        puts(str);
        printf("%d %d\n",len,n);
        da(str,sa,n+1,150);
        calheight(str,sa,n);
        RMQ(n);
        int ans=0;

        m=n;
        for(i=1;i<=n;i++){

             printf("%d:  \n",i);
             puts(str+sa[i]);
            if(sa[i]>=len) continue;
            j=len-sa[i];
            k=doit(sa[i],len+1);
            if(k>=n-len-1) j=n-len-1-1;
            k=doit(sa[i],m);
            if(j>k){
                ans+=j-k;
                printf(" %d \n",j-k);
            }
            m=sa[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
