#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
const int N=15;
bool vis[N][N];
class FoxAndClassroom{
    public:
    string ableTo(int n, int m){
        memset(vis,false,sizeof(vis));
        vis[0][0]=true;
        int cnt=1;
        int x=0,y=0;
        while(1){
            x=(x+1)%n;
            y=(y+1)%m;
            if(vis[x][y]) break;
            vis[x][y]=true;
            cnt++;
        }
        if(cnt==n*m) return "Possible";
        else  return "Impossible";
    }
};
int main(){
    //freopen("in.cpp","r",stdin);
    FoxAndClassroom a;
    cout<<a.ableTo(2,2)<<endl;

    return 0;
}
