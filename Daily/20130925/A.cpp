#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=300000+10;
char str[N],ss[N];
int n;
int minrep(char *s){
    int i=0,j=1,k=0,t;
    while(i<n&&j<n&&k<n){
        t=s[(i+k)%n]-s[(j+k)%n];
        if(!t) ++k;
        else{
            if(t>0) i=i+k+1;
            else j=j+k+1;
            if(i==j) ++j;
            k=0;
        }
    }
    return min(i,j);
}
int main(){
    //freopen("in.cpp","r",stdin);
    while(scanf("%s",ss)+1){
        //puts(ss);
        n=strlen(ss);
        for(int i=0;i<n;i++){
            int k=ss[(i+1)%n]-ss[i];
            if(k<0) k+=8;
            str[i]=k+'0';
        }
        str[n]=0;
        //puts(str);
        int k=minrep(str);
        for(int i=0;i<n;i++)
        printf("%c",str[(k+i)%n]);
        puts("");

    }
    return 0;
}
