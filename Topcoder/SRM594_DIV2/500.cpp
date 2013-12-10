#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class AstronomicalRecordsEasy{
    public:
    int minimalPlanets(vector <int> A, vector <int> B){
        for(int i=0;i<B.size();i++) A.push_back(B[i]);
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        return (int)A.size();
    }
};
int main(){
    //freopen("in.cpp","r",stdin);

    return 0;
}
