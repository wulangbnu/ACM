#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int T,cas=1;
    string s,ss;
    cin>>T;
    while(T--){
        cin>>s; ss=s;
        reverse(s.begin(),s.end());
        printf("Case %d: ",cas++);
        if(ss==s) puts("Yes");
        else puts("No");
    }
    return 0;
}
