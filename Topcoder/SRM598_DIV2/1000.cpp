#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct FoxAndFencingEasy{
    string WhoCanWin(int mov1, int mov2, int d){
        if(mov1>=d) return "Ciel";
        if(mov1>=mov2+mov2+1) return "Ciel";
        if(mov2>=mov1+mov1+1) return "Liss";
        return "Draw";
    }
};
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    FoxAndFencingEasy test;
    cout<<(test.WhoCanWin(1,58,1))<<endl;
    cout<<(test.WhoCanWin(100,100,100000000))<<endl;
    cout<<(test.WhoCanWin(100,250,100000000))<<endl;


    return 0;
}
