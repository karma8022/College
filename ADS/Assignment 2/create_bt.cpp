#include <iostream>
using namespace std;

class Treenode{
    Treenode *left,*right;
    int data;
    friend class Tree;
};

class Tree {
public:
  Treenode *createTree();

  void LVRrecursive(Treenode *root);
  void LRVrecursive(Treenode *root);
  void VLRrecursive(Treenode *root);
};

Treenode *Tree::createTree(){
    Treenode *temp;
    char choice;
    int x;
    Treenode *newnode = new Treenode;

    cout<<"Enter data for node";
    cin>>x;

    if (x==-1){
        return 0;
    }

    newnode->data =x;

    cout<<"Enter left child"<<x<<endl;
    newnode->left=createTree();

    cout<<"Enter right child"<<x<<endl;
    newnode->right=createTree();

    return newnode;
}

void Tree::LRVrecursive(Treenode *root){
    if (root==NULL){
        return;
    }
    LRVrecursive(root->left);
    LRVrecursive(root->right);
    cout<<root->data<<" ";
}

void Tree::VLRrecursive(Treenode *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    VLRrecursive(root->left);
    VLRrecursive(root->right);
}

void Tree::LVRrecursive(Treenode *root){
    if(root==NULL){
        return;
    }
    LVRrecursive(root->left);
    cout<<root->data<<" ";
    LVRrecursive(root->right);
}

int main(int argc,char const *argv[]){
    Tree t;
    Treenode *finalroot = t.createTree();
    cout<<"Post Order";
    t.LRVrecursive(finalroot);
    cout<<endl;
    cout<<"In Order";
    t.LVRrecursive(finalroot);
    cout<<endl;
    cout<<"Pre Order";
    t.VLRrecursive(finalroot);
    return 0;
}











