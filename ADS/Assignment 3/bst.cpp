#include <iostream>
#include <string>
#include <vector>
#include <fstream>


struct BstNode
{ //structuring a node
    std::string data;
    BstNode* left;
    BstNode* right;
    int frequ;
};

BstNode* NewNodeCreator(std::string data)  //creating a new node, pointing left and right to null
{
    /*I make a pointer, pointing to a new space in memory. To allocate that memory I am using new operator, taking sizeof(BstNode) struct*/
    BstNode* newNode = new BstNode();

    newNode->data = data;
    newNode->left = newNode->right = NULL; // left and right poiners to NULL
    newNode->frequ = 1; //for first time in BST
    return newNode;
}

void InPreorder(BstNode* root) //function for ptinting the BST in pre-order
{
    if (root == NULL)
        return;
    // print data of node 
    std::cout << "<" << root->frequ << ">" << " " << root->data << "\n";

    //going to left node
    InPreorder(root->left);

    //going to right
    InPreorder(root->right);
}

BstNode* InsertNode(BstNode* root, std::string data)
{ //inserting node and creating a binary tree
    if (root == NULL)
    {
        return NewNodeCreator(data);
    }
    if (data == root->data) // If the string already exists in BST, count+1 and return 
    {
        (root->frequ)++;
        return root;
    }
    else if (root->data > data)
    {
        root->left = InsertNode(root->left, data);
    }
    else
    {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

int main(){
    BstNode* root = NULL;
    InPreorder(root);
    return 0;
}