#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string.h>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
const int N=100000+10;
int pre[N];
set<int> st[N];
set<int>::iterator it;
map<string,int> mp;
string ss;
char str[20],str2[20];
int find(int i)
{
    return pre[i]==i?i:pre[i]=find(pre[i]);
}
int main()
{
     //freopen("in.cpp","r",stdin);

     int T,n,m,i,j,k;
     while(scanf("%d",&T)+1){
       mp.clear();
       for(i=0;i<N;i++){
            st[i].clear();
            pre[i]=i;
       }
       int cnt=0;
       while(T--){
          scanf("%s",str);
          if(str[0]=='a'){
             scanf("%s",str2);
             ss=str2;
             if(mp.count(ss)==0) mp[ss]=cnt++;
             int id=find(mp[ss]);
             scanf("%d",&k);
             while(k--){
                 scanf("%d",&i);
                 st[id].insert(i);
             }
          }
          else if(str[0]=='s'){
              scanf("%s",str2);
              ss=str2;
              i=find(mp[ss]);
              scanf("%s",str2);
              ss=str2;
              j=find(mp[ss]);
              if(i!=j){
                if(st[i].size()<st[j].size()) swap(i,j);
                st[i].insert(st[j].begin(),st[j].end());
                st[j].clear();
                pre[j]=i;
              }
          }
          else if(str[0]=='c'){
              scanf("%s",str2);
              ss=str2;
              if(mp.count(ss)==0){
                puts("0");
              }
              else{
                k=find(mp[ss]);
                i=st[k].size();
                printf("%d\n",i);
              }

          }
       }
     }
     return 0;
}
