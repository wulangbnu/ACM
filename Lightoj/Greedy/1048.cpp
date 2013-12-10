#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000+10;
int a[N],b[N],n,m;
int check(int x)
{
    int ret=0,i,j;
    for(i=0;i<=n;){
        int sum=a[i];
        for(j=i+1;(sum+=a[j])<=x;j++);
        b[ret++]=sum-a[j];
        i=j;
    }
    return ret;
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,i,j,k,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m); m++;

        int x=0,y=10000000+1,cnt;
        for(i=0;i<=n;i++){
            scanf("%d",&a[i]);
            x=max(x,a[i]);
        }
        a[n+1]=100000000;
        while(x<y){
            int mid=(y-x)/2+x;
            cnt=check(mid);
            //printf("%d %d\n",mid,cnt);
            if(cnt<=m) y=mid;
            else x=mid+1;
        }
        printf("%d\n",x);
        j=check(x);
        k=n;
        int sum=0;
        for(i=m-1;i>=j;i--){
            b[i]=a[k];
            sum+=a[k];
            k--;
        }
        for(i=j-1;i>=0;i--){
            if(b[i]>=sum+a[k]){
                 b[i]-=sum;
                 break;
            }
            else{
                sum-=b[i]-a[k];
                b[i]=a[k];
            }
        }
        for(i=0;i<m;i++)
        printf("%d\n",b[i]);

    }
    return 0;
}
