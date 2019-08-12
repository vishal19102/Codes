#include<bits/stdc++.h>

using namespace std;

void buildTree(int *arr,int *tree,int start, int end,int treeNode){

    if(start==end)
        {
            tree[treeNode]=arr[start];
            return ;
        }
    
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);



}
void updateTree(int *arr,int *tree,int start,int end,int idx,int value,int treeNode){

    if(start==end)
        {
            arr[idx]=value;
            tree[treeNode]=value;
            return ;
        }

    int mid=(start+end)/2;

    if(idx<mid)
        updateTree(arr,tree,start,mid,idx,value,2*treeNode);
    else
    {
            updateTree(arr,tree,mid+1,end,idx,value,2*treeNode+1);
    }

}
int queryTree(int *tree,int start,int end,int lqery,int rqery,int treeNode){

    //completely outside
    if(lqery>end||rqery<start)  
        return 0;
    //completely inside
    if(lqery>=start&&rqery<=end)
        return tree[treeNode];
    //partially inside
    int mid=(start+end)/2;

    int ans1=queryTree(tree,start,mid,lqery,rqery,2*treeNode);
    int ans2=queryTree(tree,mid+1,end,lqery,rqery,2*treeNode+1);

    return min(ans1,ans2);
}
int main(){

    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int *tree = new int[4*n];

    buildTree(arr,tree,0,4,1); 

   int ans1= queryTree(tree,0,4,1,4,1);
   cout<<"Ans 1 is "<<ans1<<endl;

   int ans2= queryTree(tree,0,4,1,2,1);

    cout<<"Ans 2 is "<<ans2<<endl;

   updateTree(arr,tree,0,4,3,6,1);
   
int ans3= queryTree(tree,0,4,1,4,1);

    cout<<"Ans 3 is "<<ans3<<" and "<<tree[3]<<endl;
    
    }

