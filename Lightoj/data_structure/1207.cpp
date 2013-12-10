#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200000+10;
struct node
{
    int left,right,tag,sum;
}tree[N*5];
void build(int k,int left,int right)
{
    tree[k].left=left; tree[k].right=right; tree[k].tag=-1; tree[k].sum=0;
    if(left<right){
        int mid=(left+right)/2;
        build(2*k,left,mid);
        build(2*k+1,mid+1,right);
    }
}
void insert(int k,int left,int right,int val)
{
    if(tree[k].left==left&&tree[k].right==right){
        tree[k].tag=val;
        tree[k].sum=1;
        return;
    }
    int mid=(tree[k].left+tree[k].right)/2;
    if(tree[k].tag!=-1){
        insert(2*k,tree[k].left,mid,tree[k].tag);
        insert(2*k+1,mid+1,tree[k].right,tree[k].tag);
        tree[k].tag=-1;
    }
    if(right<=mid) insert(2*k,left,right,val);
    else if(left>=mid+1) insert(2*k+1,left,right,val);
    else{
        insert(2*k,left,mid,val);
        insert(2*k+1,mid+1,right,val);
    }
    tree[k].sum=tree[2*k].sum+tree[2*k+1].sum;
}
int query()
{
    return tree[1].sum;
}
int main()
{
    freopen("in.cpp","r",stdin);

    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d: ",cas++);
        scanf("%d",&n);
        build(1,1,2*n);
        while(n--){
            scanf("%d%d",&i,&j);
            insert(1,i,j,n);
            printf("%d\n",query());
        }
        //printf("%d\n",query());
    }
    return 0;
}

