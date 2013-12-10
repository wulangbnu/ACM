#include <cstdio>
#include <cstring>
int main(){
    //freopen("in.cpp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        double sum=0,x;
        for(int i=0;i<12;i++){
            scanf("%lf",&x);
            sum+=x;
        }
        char str[100];
        sprintf(str,"%.2f",sum/12);
        int len=strlen(str);
        if(str[len-1]=='0'&&str[len-2]=='0') str[len-3]=0;
        else if(str[len-1]=='0') str[len-1]=0;
        printf("$%s\n",str);
    }
    return 0;
}
