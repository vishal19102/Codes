#include<bits/stdc++.h>

using namespace std;


class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        data=d;
        left = NULL;
        right=NULL;

    }

};
node * buildTree(){
    int d;
    cin>>d;

    if(d==-1)
        return NULL;
    
            node* k = new node(d);
            k->left=buildTree();
            k->right=buildTree();

        
        return k;

    }

 void printTree(node * root){
     if(root==NULL)
        return;
    cout<<root->data<<" ";
    printTree(root->left);
    
    printTree(root->right);
 }   
int main(){
    node * root;
    root=buildTree();
    printTree(root);


}