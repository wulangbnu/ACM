#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100000+10;
struct node
{
    int left,right,sum,tag;
}tree[N*3];
void build(int k,int left,int right)
{
    tree[k].left=left; tree[k].right=right;
    tree[k].sum=0; tree[k].tag=-1;
    if(left<right){
        int mid=(left+right)/2;
        build(2*k,left,mid);
        build(2*k+1,mid+1,right);
    }
}
void insert(int k,int left,int right,int val)
{
    if(left==tree[k].left&&right==tree[k].right){
        tree[k].tag=val;
        tree[k].sum=tree[k].tag*(tree[k].right-tree[k].left+1);
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
int query(int k,int left,int right)
{
    if(left>=tree[k].left&&right<=tree[k].right&&tree[k].tag!=-1){
        return tree[k].tag*(right-left+1);
    }
    if(tree[k].left==left&&tree[k].right==right){
        return tree[k].sum;
    }
    int mid=(tree[k].left+tree[k].right)/2;
    if(tree[k].tag!=-1){
        insert(2*k,tree[k].left,mid,tree[k].tag);
        insert(2*k+1,mid+1,tree[k].right,tree[k].tag);
        tree[k].tag=-1;
    }
    if(right<=mid){
        return query(2*k,left,right);
    }
    else if(left>=mid+1){
        return query(2*k+1,left,right);
    }
    else {
        return query(2*k,left,mid)+query(2*k+1,mid+1,right);
    }
}
int main()
{
    //freopen("in.cpp","r",stdin);

    int T,cas=1,n,m,i,j,k,r;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);

        scanf("%d%d",&n,&m);
        build(1,0,n-1);
        while(m--){
            scanf("%d%d%d",&k,&i,&j);
            if(k==1){
                scanf("%d",&r);
                insert(1,i,j,r);
            }
            else{
                int sum=query(1,i,j);
                int p=__gcd(sum,j-i+1);
                if((j-i+1)/p!=1)
                printf("%d/%d\n",sum/p,(j-i+1)/p);
                else printf("%d\n",sum/p);
            }
        }
    }
    return 0;
}
