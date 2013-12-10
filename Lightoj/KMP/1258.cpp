#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000000+10;
char s[N],t[N];
int next[N];
void get_next()
{
    int i=0,j=-1;
    next[0]=-1;
    while(t[i]){
        if(j==-1||t[i]==t[j]) next[++i]=++j;
        else  j=next[j];
    }
}
void kmp(int n)
{
    int i=0,j=0;
    while(i<n&&j<n){
        if(j==-1||s[i]==t[j]) i++,j++;
        else j=next[j];
    }
    printf("%d\n",2*n-j);
}
int main()
{
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%s",s);
        int n=strlen(s);
        for(i=0;i<n;i++)
        t[n-1-i]=s[i];
        get_next();
        kmp(n);
    }
    return 0;
}

