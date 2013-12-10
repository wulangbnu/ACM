#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=50000+10;
int wa[N],wb[N],wv[N],ws[N],sa[N];
char str[N],t[N];
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
int *next=wv,*a=ws,cnt;
void get_next(char t[])
{
    int i=0,j=-1;
    next[0]=-1;
    while(t[i]){
        if(j==-1||t[i]==t[j]) next[++i]=++j;
        else j=next[j];
    }
}
void kmp(char s[],char t[])
{
    int i=0,j=0;
    cnt=0;
    int ls=strlen(s),lt=strlen(t);
    while(i<ls&&j<lt){
        if(j==-1||s[i]==t[j]) i++,j++;
        else j=next[j];
        if(j==lt){
            a[cnt++]=i-lt;
            j=next[j];
        }
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",str);
        n=strlen(str);
        da(str,sa,n+1,150);
        calheight(str,sa,n);
        scanf("%s",t);
        get_next(t);
        int len=strlen(t);
        kmp(str,t);
        //for(i=0;i<cnt;i++) printf("%d\n",a[i]);
        int ans=0;
        for(i=1;i<=n;i++){
            k=lower_bound(a,a+cnt,sa[i])-a;
            if(k==cnt) ans+=n-sa[i]-height[i];
            else{
                if(a[k]+len-1-sa[i]-height[i]>0)
                ans+=a[k]+len-1-sa[i]-height[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
