#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=15000+10;
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
int tag1,tag2,tag3,len1,len2,len3;
void work(int x)
{
    if(x<len1) tag1=1;
    else if(x<len2) tag2=1;
    else if(x<len3) tag3=1;
}
bool check(int mid,int n)
{
    int i,j,k=1;
    while(k<=n){
        if(height[k]<mid) k++;
        else{
            tag1=tag2=tag3=0;
            work(sa[k-1]);
            i=k;
            while(i<=n&&height[i]>=mid){
                work(sa[i]);
                i++;
            }
            if(tag1==1&&tag2==1&&tag3==1) return true;
            k=i;
        }
    }
    return false;
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",str);
        len1=strlen(str);
        str[len1]='#';
        scanf("%s",str+len1+1);
        len2=strlen(str);
        str[len2]='#';
        scanf("%s",str+len2+1);
        len3=strlen(str);
        n=len3;

//        puts(str);
//        printf("%d %d %d\n",len1,len2,len3);

        da(str,sa,n+1,150);
        calheight(str,sa,n);

        int x=0,y=5005,mid;
        while(x<y){
            mid=(x+y+1)/2;
            if(check(mid,n)) x=mid;
            else y=mid-1;
        }
        printf("%d\n",x);
    }
    return 0;
}
