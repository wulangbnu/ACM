#include<cstdio>
#include<cstring>
#define N 1005
int p[N];
int main()
{
    int T,n,k,i,j;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",cas++);

        memset(p,0,sizeof(p));
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d %d",&j,&i);
                p[i]++;
                p[j]--;
            }
        }
        for(j=k=n=i=0;i<N;i++)
        {
         if(p[i]==1) j++;
         else if(p[i]==-1) k++;
         else if(p[i]!=0) n++;
        }
        if(j==1&&k==1&&n==0) puts("YES");
        else puts("NO");


    }
    return 0;
}
