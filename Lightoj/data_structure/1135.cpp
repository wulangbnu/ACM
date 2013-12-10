#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100000+10;
struct node
{
    int left,right,x,y,z,add;
}tree[N*5];
void build(int k,int left,int right)
{
    tree[k].left=left; tree[k].right=right;
    tree[k].x=right-left+1;
    tree[k].y=tree[k].z=tree[k].add=0;
    if(left==right) return;
    int mid=(left+right)/2;
    build(2*k,left,mid);
    build(2*k+1,mid+1,right);
}
void insert(int k,int left,int right,int val)
{
    val%=3;
    if(val==0) return;
    if(left==tree[k].left&&right==tree[k].right){
       if(val==1){
            tree[k].z=tree[k].y;
            tree[k].y=tree[k].x;
            tree[k].x=right-left+1-tree[k].y-tree[k].z;
       }
       else if(val==2){
            tree[k].x=tree[k].y;
            tree[k].y=tree[k].z;
            tree[k].z=right-left+1-tree[k].x-tree[k].y;
       }
       tree[k].add+=val;
       return;
    }
    int mid=(tree[k].left+tree[k].right)/2;

    //push_down操作
    tree[k].add%=3;
    if(tree[k].add){
        insert(2*k,tree[k].left,mid,tree[k].add);
        insert(2*k+1,mid+1,tree[k].right,tree[k].add);
        tree[k].add=0;
    }


    if(right<=mid){
        insert(2*k,left,right,val);
    }
    else if(left>=mid+1){
        insert(2*k+1,left,right,val);
    }
    else{
        insert(2*k,left,mid,val);
        insert(2*k+1,mid+1,right,val);
    }
    tree[k].add=0;
    tree[k].x=tree[2*k].x+tree[2*k+1].x;
    tree[k].y=tree[2*k].y+tree[2*k+1].y;
    tree[k].z=tree[2*k].z+tree[2*k+1].z;
}
int query(int k,int left,int right)
{
   if(left==tree[k].left&&right==tree[k].right){
        return tree[k].x;
   }
   int mid=(tree[k].left+tree[k].right)/2;

   //push_down操作
   tree[k].add%=3;
   if(tree[k].add){
        insert(2*k,tree[k].left,mid,tree[k].add);
        insert(2*k+1,mid+1,tree[k].right,tree[k].add);
        tree[k].add=0;
   }

   if(right<=mid) return query(2*k,left,right);
   else if(left>=mid+1) return query(2*k+1,left,right);
   else return query(2*k,left,mid)+query(2*k+1,mid+1,right);
}
int main()
{
    int T,cas=1,n,m,i,j,k;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cas++);
        scanf("%d%d",&n,&m);
        build(1,0,n-1);
        while(m--){
            scanf("%d%d%d",&i,&j,&k);
            if(i==0) insert(1,j,k,1);
            else printf("%d\n",query(1,j,k));
        }
    }
    return 0;
}
