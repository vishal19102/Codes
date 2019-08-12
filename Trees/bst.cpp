#include<iostream>

using namespace std;

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
 
    //insert elements in the bst
    node* insert(node *temp,int d){
        
        if(temp==NULL)
            {
                node* child= new node(d); 
                return child;
            }
        
            if(d<temp->data)
                temp->left=insert(temp->left,d);
            else if(d>temp->data)
                temp->right=insert(temp->right,d);
             

        return temp;
    }

    //printing the tree values 
    void printTree(node* root){

        if(root==NULL)
            return ;

        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
    }



int main(){

    node* root;
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,11);
    root=insert(root,4);
    printTree(root);
    return 0;
}