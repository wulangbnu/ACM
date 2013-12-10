#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100+10;
const int M=1980;
int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int year){
    return  year%400==0||(year%4==0&&year%100!=0);
}
int x[N],y[N],n,ans;
int s1,s2;
int input(int month,int day,int year,int type=0){
    int ret=0;
    if(type) scanf("%d/%d/%d",&month,&day,&year);
    for(int i=M;i<year;i++)
    ret+=365+check(i);
    for(int i=1;i<month;i++){
        ret+=mon[i];
        if(i==2) ret+=check(year);
    }
    ret+=day;
    return ret;
}
int doit(int s,int t){
    if(s>t) return 0;
    int ret=t-s;
    for(int i=0;i<n;i++){
        int a=max(x[i],s);
        int b=min(y[i]+1,t);
        if(b-a>0) ret-=b-a;
    }
    return ret;
}
bool work(int ans){
    int ss1=max(s1,ans-1460);
    int ss2=max(s2,ans-1460);
    int a=doit(ss1,min(ss2,ans));
    a=min(a,730);
    int b=doit(ss2,ans);
    if(a/2+b>=1095) return true;
    else return false;
}
void output(int ans){
    int year,month,day,tot;

    for(tot=0,year=M;;year++){
        tot+=365+check(year);
        if(tot>=ans) break;
    }
    //year--;
    for(int i=M;i<year;i++) ans-=365+check(i);

    for(tot=0,month=1;;month++){
        tot+=mon[month];
        if(month==2) tot+=check(year);
        if(tot>=ans) break;
    }
    for(int i=1;i<month;i++) ans-=mon[i]+(i==2&&check(year));

    day=ans;

    printf("%d/%d/%d\n",month,day,year);
}
int main(){
    freopen("in.cpp","r",stdin);
    int month,day,year;
    while(scanf("%d/%d/%d",&month,&day,&year)+1){
        ans=0;
        s1=input(month,day,year);
        s2=input(month,day,year,1);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            x[i]=input(month,day,year,1);
            y[i]=input(month,day,year,1);
        }
        for(;!work(ans);ans++);
        output(ans);
    }
    return 0;
}
