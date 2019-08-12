#include<iostream>

using namespace std;

class Node{
    public :
        int data;
        Node* right;
        Node* left;
    Node(int dat){
            data=dat;
            left=NULL;
            right=NULL;
    }
};
Node* insert(Node* root,int data){

    if(root==NULL){
        Node* child=new Node(data);

        return child; 
        }
        if(data<root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);


        return root;            

}
int getHeight(Node* root){
    int height;
    if(root==NULL)
        return 0;

    int ans1=getHeight(root->right);
    int ans2=getHeight(root->left);
    height=max(ans1,ans2)+1;
    return height; 
}
void Inorder(Node* root){
    if(root==NULL)
        return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void printkthLevel(Node* root,int level){
    if(level==1)
        {
            cout<<root->data<<" ";
            return ;
        }
        printkthLevel(root->left,level-1);
        printkthLevel(root->right,level-1);
}
void printLevelTree(Node* root){
    int levels=getHeight(root);
    for(int i=1;i<=levels;i++)
        printkthLevel(root,i);
    
}
int main(){
    Node* root;
    
    /* for(int i=0;i<n;i++){
            int a;
            cin>>a;
            root=insert(root,a);
    }*/
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,12);
    root=insert(root,21);
    Inorder(root);
    printLevelTree(root);
    return 0;
}