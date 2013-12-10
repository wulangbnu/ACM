#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
string s[]={
"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"
};
int doit(string ss){
    for(int i=0;i<12;i++)
    if(s[i]==ss) return i+1;
}
int solve(int y){
    return  y/4-y/100+y/400;
}
bool check(int y){
    return ((y%4==0&&y%100!=0)||y%400==0);
}
string ss;
int m1,d1,y1,m2,d2,y2;
int main(){
    //freopen("in.cpp","r",stdin);
    int T,cas=1,n,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        cin>>ss;
        scanf("%d, %d",&d1,&y1);
        m1=doit(ss);
        cin>>ss;
        scanf("%d, %d",&d2,&y2);
        m2=doit(ss);
        int ans=solve(y2)-solve(y1-1);
        if(check(y1)&&m1>2) ans--;
        if(check(y2)&&(m2<2||(m2==2&&d2<29))) ans--;
        printf("%d\n",ans);
    }
    return 0;
}
