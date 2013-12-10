#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=5000;
struct MiniatureDachshund{
    int maxMikan(vector <int> mikan, int weight){
        sort(mikan.begin(),mikan.end());
        int ans=-1;
        for(int i=0;i<mikan.size();i++){
            if(weight+mikan[i]<=N){
               ans=i;
               weight+=mikan[i];
            }
        }
        return ans+1;
    }
};
int main(){
    #ifdef wulang
        freopen("in.cpp","r",stdin);
    #endif


    return 0;
}
