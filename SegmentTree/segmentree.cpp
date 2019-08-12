#include<bits/stdc++.h>

using namespace std ;

void segmentTree(int *arr,int* tree,int treeNode,int start,int end){

    if(start==end)
        {
            tree[treeNode]=arr[start];
            return ;
        }
        int mid=(start+end)/2;
        segmentTree(arr,tree,2*treeNode,start,mid);
        segmentTree(arr,tree,2*treeNode+1,mid+1,end);

        tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];


    return ;
}

void update(int *arr,int *tree,int start,int end,int treeNode,int idx,int value){

    if(start==end){
        arr[idx]=value;
        tree[treeNode]=value;
        return ;
    }
    int mid=(start+end)/2;
    if(idx<mid)
        update(arr,tree,start,mid,2*treeNode,idx,value);
    else
        update(arr,tree,mid+1,end,2*treeNode+1,idx,value);

    tree[treeNode]=tree[treeNode*2]+tree[2*treeNode+1];

    return ;
}
int queryTree(int *tree,int treeNode,int start,int end,int lqu,int rqu){
    int ans=0;

    if(lqu>end||rqu<start)
        return 0;
    if(lqu>start&&rqu<=end)
        return tree[treeNode];

    int mid =(start+end)/2;
    int op1= queryTree(tree,2*treeNode,start,mid,lqu,rqu);
    int op2=queryTree(tree,2*treeNode+1,mid+1,end,lqu,rqu);    
    ans=op1+op2;

    return ans;
}
int main(){

    int arr[]={2,3,4,5,6,7};

    int size=sizeof(arr)/sizeof(int);

    int *tree= new int[size*4];

    segmentTree(arr,tree,1,0,size-1);


    return 0;
}