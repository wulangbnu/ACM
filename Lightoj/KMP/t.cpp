#include<cstdio>
#include<cstring>
#define N 1000005
char S[N],T[N];
int next[N],extend[N];
void get_next(char *T)
{
    int i=0,j,k;
    next[0]=0;
    while(T[i]==T[i+1]) i++;
    next[1]=i;
    for(k=1,i=2;T[i];i++)
    {
        if(next[i-k]+i<next[k]+k) next[i]=next[i-k];
        else
        {
            j=next[k]+k-i;
            if(j<0) j=0;
            while(T[j+i]==T[j]&&T[j+i]) j++;
            next[i]=j;
            k=i;
        }
    }
}
void get_extend(char *S,char *T)
{
    int i=0,j,k;
    while(S[i]==T[i]&&S[i]&&T[i]) i++;
    extend[0]=i;
    for(k=0,i=1;T[i];i++)
    {
        if(next[i-k]+i<extend[k]+k)  extend[i]=next[i-k];
        else
        {
            j=extend[k]+k-i;
            if(j<0) j=0;
            while(S[j+i]==T[j]&&S[j+i]&&T[j]) j++;
            extend[i]=j;
            k=i;
        }
    }

}
int main()
{
    //freopen("in.cpp","r",stdin);
    int TT,cas=1,i,j,k;
    scanf("%d",&TT);
    while(TT--)
    {
        printf("Case %d: ",cas++);
        scanf("%s",S);
        for(j=0,i=strlen(S)-1;i>=0;i--)
        T[j++]=S[i];
        get_next(T);
        get_extend(S,T);
        for(i=0;i<j;i++)
        if(extend[i]+i==j) break;
        printf("%d\n",j+i);
    }
    return 0;
}
