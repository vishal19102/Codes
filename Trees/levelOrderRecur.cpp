#include<bits/stdc++.h>

using namespace std ; 

class node{
    public :
        int data;
        node* left;
        node* right;
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* buildTree(){
    int d;
    cin>>d;

    if(d==-1)
        return NULL;

    node* root= new node(d);
    root->left=buildTree();
    root->right= buildTree();

}
void printkthLevel(node* root,int l){

    if(root==NULL)
        return ;
    if(l==1){
            cout<<root->data<<" ";
        return ;
    }
    //cout<<"came here"<<endl;
    printkthLevel(root->left,l-1);
    printkthLevel(root->right,l-1);
}

int heightTree(node* root){
    if(root==NULL)
        return 0;
    int opt1= heightTree(root->left)+1;
    int opt2= heightTree(root->right)+1;

    return max(opt1,opt2);
}
void levelOrder(node* root){
    //cout<<"c";
    int levels= heightTree(root);
    for(int i=1;i<=levels;i++)
        printkthLevel(root,i);
}
int main(){

    node* root = buildTree();
    levelOrder(root);    

}