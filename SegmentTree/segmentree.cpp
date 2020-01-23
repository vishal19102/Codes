
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <string>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef long long int ll;
typedef pair<string,int> pp;

//create segment tree....
void segmentTree(int* arr,int *tree, int start,int end, int treeNode){
    if(start==end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    segmentTree(arr,tree,start,mid,2*treeNode);
    segmentTree(arr,tree,mid+1,end,2*treeNode+1);
    
    tree[treeNode] = tree[treeNode*2]+tree[treeNode*2+1];
    
    return ;
    }

//update segment tree...
void update(int* arr, int * tree, int start, int end,int treeNode,int idx,int value){

    if(start==end){
        arr[idx] = value;
        tree[treeNode] = arr[idx];
        return ;
    }
    int mid= (start+end)/2;
    if(idx<=mid)
        update(arr,tree,start,mid,2*treeNode,idx,value);
    else
        update(arr,tree,mid+1,end,2*treeNode+1,idx,value);

    tree[treeNode] = tree[treeNode*2]+tree[treeNode*2+1];

    return ;
}

//query segment tree...
int queryTree(int* tree,int start,int end,int lqu,int rqu,int treeNode){

    //cout<<"Came here"<<endl;
    if(lqu>end||rqu<start){
        return 0;
    }

    if(lqu<=start&&rqu>=end){
        return tree[treeNode];
    }
    //cout<<"Came here"<<endl;
    int mid = (start+end)/2;
    int ans1 =queryTree(tree,start,mid,lqu,rqu,treeNode*2);
    int ans2 =queryTree(tree,mid+1,end,lqu,rqu,treeNode*2+1);
    int ans = ans1 +ans2;
    //cout<<ans<<endl;
    return ans;
}


int main(){

    int n ;
    cin>>n;
    int* arr  = new int[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int* tree = new int[4*n];
    
    segmentTree(arr,tree,0,n-1,1);
    
    for(int i =0;i<4*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<queryTree(tree,0,n-1,1,3,1)<<endl;
    update(arr,tree,0,n-1,1,1,10);
    cout<<queryTree(tree,0,n-1,1,3,1)<<endl;
    return 0;
}

