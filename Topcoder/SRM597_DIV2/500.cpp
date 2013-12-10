#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
class LittleElephantAndString{
    public :
    int getNumber(string A, string B){
        int cnt[26]={0}, n=int(A.size());
        for(int i=0;i<n;i++){
            cnt[A[i]-'A']++;
            cnt[B[i]-'A']--;
        }
        for(int i=0;i<26;i++) if(cnt[i]!=0) return -1;

        int ans=0;
        for(int i=n-1,j=n-1;i>=0&&j>=0;){
            if(A[i]==B[j]){
                i--;
                j--;
            }else{
                i--;
                ans++;
            }
        }
        return ans;
    }
};
int main(){
    freopen("in.cpp","r",stdin);
    string A,B;
    LittleElephantAndString test;
    while(cin>>A>>B){
        //cout<<A<<" "<<B<<endl;
        cout<<test.getNumber(A,B)<<endl;
    }
    return 0;
}
