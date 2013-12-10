#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct BinPackingEasy{
    int minBins(vector <int> item){

        sort(item.begin(),item.end());
        int ans=0, n=item.size();
        int x=0,y=n-1,cnt=0;
        while(x<y){
            if(item[x]+item[y]<=300){
                x++; y--;
                cnt++;
            }
            else y--;
        }
        ans+=cnt+(n-cnt*2);
        return ans;
    }
};
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif
    vector<int> item;
    item.push_back(150);
    item.push_back(150);
    item.push_back(150);
    item.push_back(150);
    item.push_back(150);

    BinPackingEasy test;
   cout<<test.minBins(item)<<endl;

    return 0;
}
