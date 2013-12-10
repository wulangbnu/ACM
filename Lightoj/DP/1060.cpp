#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 30
int a[N],f[N];
int c[N];
long long b[N];
char str[N];
int n;
long long m;
void init()
{
    b[0]=b[1]=1;
    for(int i=2;i<=20;i++)
    b[i]=b[i-1]*i;
}
long long calc(int x)
{
    memset(f,0,sizeof(f));
    for(int i=x+1;i<=n;i++)
    f[a[i]]++;
    long long res=b[n-x];
    for(int i=0;i<26;i++){
        res/=b[f[i]];
    }
    return res;
}
void doit(int x)
{
    if(x==n+1){
        m--;
        return;
    }
    long long tmp=calc(x);
    //cout<<x<<"  "<<tmp<<"  "<<m<<endl;
    if(m<=tmp) doit(x+1);
    else{
        m-=tmp;
        for(int i=x+1;i<=n;i++){
            if(a[i]==a[x]||a[i]==a[i-1]) continue;
            memcpy(c,a,sizeof(a));
            swap(a[x],a[i]);
            sort(a+x+1,a+n+1);
            tmp=calc(x);
            if(m<=tmp) {
                doit(x+1);
                return;
            }
            m-=tmp;
            memcpy(a,c,sizeof(a));
        }
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);

    init();
    int T,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s%d",str,&k);
        m=k;
        n=0;
        for(i=0;str[i];i++){
            a[++n]=str[i]-'a';
        }
        sort(a+1,a+1+n);
        doit(1);
        if(m==0){
            for(i=1;i<=n;i++)
            printf("%c",a[i]+'a');
            puts("");
        }
        else {
            puts("Impossible");
        }

    }
    return 0;
}
