#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<fstream>
using namespace std;
long long ans[100][100]={
{0},{0},{0},

{2},
{3},
{5},
{2,2,2},
{13},
{3,7},
{2,17},
{5,11},
{89},
{2,2,2,2,3,3},
{233},
{13,29},
{2,5,61},
{3,7,47},
{1597},
{2,2,2,17,19},
{37,113},
{3,5,11,41},
{2,13,421},
{89,199},
{28657},
{2,2,2,2,2,3,3,7,23},
{5,5,3001},
{233,521},
{2,17,53,109},
{3,13,29,281},
{514229},
{2,2,2,5,11,31,61},
{557,2417},
{3,7,47,2207},
{2,89,19801},
{1597,3571},
{5,13,141961},
{2,2,2,2,3,3,3,17,19,107},
{73,149,2221},
{37,113,9349},
{2,233,135721},
{3,5,7,11,41,2161},
{2789,59369},
{2,2,2,13,29,211,421},
{433494437ll},
{3,43,89,199,307},
{2,5,17,61,109441},
{139,461,28657},
{2971215073ll},
{2,2,2,2,2,2,3,3,7,23,47,1103},
{13,97,6168709},
{5,5,11,101,151,3001},
{2,1597,6376021},
{3,233,521,90481},
{953,55945741},
{2,2,2,17,19,53,109,5779},
{5,89,661,474541},
{3,7,7,13,29,281,14503},
{2,37,113,797,54833},
{59,19489,514229},
{353,2710260697ll},
{2,2,2,2,3,3,5,11,31,41,61,2521},
{4513,555003497ll},
{557,2417,3010349},
{2,13,17,421,35239681ll},
{3,7,47,1087,2207,4481},
{5,233,14736206161ll},
{2,2,2,89,199,9901,19801},
{269,116849,1429913},
{3,67,1597,3571,63443},
{2,137,829,18077,28657},
{5,11,13,29,71,911,141961},
{6673,46165371073ll},
{2,2,2,2,2,3,3,3,7,17,19,23,107,103681},
{9375829,86020717},
{73,149,2221,54018521},
{2,5,5,61,3001,230686501ll},
{3,37,113,9349,29134601},
{13,89,988681,4832521},
{2,2,2,79,233,521,859,135721},
{157,92180471494753ll},
{3,5,7,11,41,47,1601,2161,3041},
{2,17,53,109,2269,4373,19441},
{2789,59369,370248451ll},
{99194853094755497ll},
{2,2,2,2,3,3,13,29,83,211,281,421,1427},
{5,1597,9521,3415914041ll},
{6709,144481,433494437},
{2,173,514229,3821263937ll},
{3,7,43,89,199,263,307,881,967},
{1069,1665088321800481ll},
{2,2,2,5,11,17,19,31,61,181,541,109441},
{13,13,233,741469,159607993ll,},
{3,139,461,4969,28657,275449}
};
long long f[100];

long long a,b;
char aa[20],bb[20];
int flag;
void gao()
{
    a=0ll;
    for(int i=2;i<strlen(aa);i++)
    {
        a=a*16;
        if(aa[i]>='0'&&aa[i]<='9')a+=aa[i]-'0';
        else if(aa[i]>='a'&&aa[i]<='z')a+=aa[i]-'a'+10;
        else a+=aa[i]-'A'+10;
    }

    b=0ll;
    for(int i=2;i<strlen(bb);i++)
    {
        b=b*16;
        if(bb[i]>='0'&&bb[i]<='9')b+=bb[i]-'0';
        else if(bb[i]>='a'&&bb[i]<='z')b+=bb[i]-'a'+10;
        else b+=bb[i]-'A'+10;
    }

   // cout<<a<<","<<b<<endl;
}
int main()
{
    freopen("in.cpp","r",stdin);
    freopen("out2.txt","w",stdout);

    f[0]=0ll;f[1]=1ll;
    for(int i=2;i<=92;i++)
        f[i]=f[i-1]+f[i-2];
    int _=0;

    while(scanf("%llx %llx",&a,&b)!=EOF )
    {
        //cout<<"!!!"<<b<<endl;
        //if(_)printf("\n");
       // _=1;
        //cout<<bb<<endl;
        flag=0;
        //gao();

        //cout<<b<<endl;
        if(a>b || b==0)break;
        //printf("Range %lld to %lld:\n",a,b);
        cout<<"Range "<<a<<" to "<<b<<":\n";
        for(int i=0;i<93;i++)
        {
            if(f[i]>=a)
            {
                if(f[i]<=b)
                {
                    flag=1;
                    //printf("Fib(%d) = %lld, lg ",i,f[i]);
                    cout<<"Fib("<<i<<") = "<<f[i]<<", lg ";
                    if(i==0)
                        printf("does not exist\n");
                    else
                        printf("is %.6f\n",log(1.0*f[i])/log(2));
                    if(i<3)
                        printf("No prime factors\n");
                    else
                    {
                        printf("Prime factors:");
                        for(int j=0;;j++)
                        {
                            if(ans[i][j]!=0ll)
                            {
                                //printf(" %lld",ans[i][j]);
                                cout<<" "<<ans[i][j];
                            }
                            else
                            {
                                printf("\n");
                                break;
                            }
                        }
                    }
                }
                else
                    break;
            }
        }
        if(!flag)
        {
            printf("No Fibonacci numbers in the range\n");
        }
        printf("\n");
    }


    return 0;
}

/*
0x0 0x7FFFFFFFFFFFFFFF
*/
