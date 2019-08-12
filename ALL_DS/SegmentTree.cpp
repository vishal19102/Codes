#include<iostream>

using namespace std;

void buildSegmentTree(int *arr,int *tree,int start,int end,int treeNode){

    if(start==end)
        {
            tree[treeNode]=arr[start];
            return ;
         }
    int mid=(start+end)/2;
    buildSegmentTree(arr,tree,start,mid,2*treeNode);
    buildSegmentTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];

    return;
}
void updateTree(int *arr,int *tree,int start,int end,int idx,int value,int treeNode){

        if(start==end)
            {
                arr[idx]=value;
                tree[treeNode]=value;
                return;
            }
            int mid=(start+end)/2;
            updateTree(arr,tree,start,mid,idx,value,2*treeNode);
            updateTree(arr,tree,mid+1,end,idx,value,2*treeNode+1);
            tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];

    return ;
}
int queryTree(int *tree,int start,int end,int lquery,int rquery,int treeNode){

    if(lquery>end||rquery<start)
            return 0;
    
    if(lquery>=start&&rquery<=end)
            return tree[treeNode];

    int mid=(start+end)/2;
    int ans1=queryTree(tree,start,mid,lquery,rquery,2*treeNode);
    int ans2=queryTree(tree,mid+1,end,lquery,rquery,2*treeNode+1);

    return ans1+ans2;
}
int main(){

    int n;
    cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *tree= new int[4*n];
    buildSegmentTree(arr,tree,0,n-1,1);

    return 0;

}