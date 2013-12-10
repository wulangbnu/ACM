#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct LittleElephantAndDouble{
    string getAnswer(vector <int> A){
        for(int i=0;i<A.size();i++){
            while(A[i]%2==0) A[i]>>=1;
        }
        for(int i=0;i<A.size();i++){
            if(A[i]!=A[0]) return "NO";
        }
        return "YES";
    }
};
int main(){
    return 0;
}
