#include <iostream>
using namespace std;
class treenode
{
  string data, meaning;
  treenode *left, *right;
  friend class bstree;
};
class bsqueue
{
  int front, rear;
  treenode *data[30];

public:
  bsqueue()
  {
    front = -1;
    rear = -1;
  }

  void push(treenode *temp)
  {
    rear++;
    data[rear] = temp;
  }
  treenode *pop()
  {
    treenode *temp;
    front++;
    temp = data[front];
    return temp;
  }
  int is_empty()
  {
    int isempty;
    if (front == rear)
    {
      isempty = 0;
    }
    else
    {
      isempty = 1;
    }
    return isempty;
  }
};
class bstree
{
  treenode *root;

public:
  bstree()
  {
    root = NULL;
  }
  struct treenode *create_bstree()
  {
    treenode *ptr, *temp;
    char ch;
    int flag;
    do
    {
      ptr = new treenode;
      cout << "Enter data of node: ";
      cin >> ptr->data;
      cout << "Enter meaning of node: ";
      cin >> ptr->meaning;
      ptr->left = ptr->right = NULL;
      if (root == NULL)
      {
        root = ptr;
      }
      else
      {
        temp = root;
        flag = 0;
        while (flag != 1)
        {
          if (ptr->data < temp->data)
          {
            if (temp->left == NULL)
            {
              temp->left = ptr;
              flag = 1;
              break;
            }
            else
            {
              temp = temp->left;
              flag = 0;
            }
          }
          else
          {
            if (temp->right == NULL)
            {
              temp->right = ptr;
              flag = 1;
              break;
            }
            else
            {
              temp = temp->right;
              flag = 0;
            }
          }
        }
      }
      cout << "Do you want to continue?";
      cin >> ch;
    } while (ch == 'y');
    return root;
  }
  void level_order(treenode *root)
  {
    treenode *temp;
    if (root == NULL)
      return;

    bsqueue q;
    q.push(root);
    while (q.is_empty() == 1)
    {
      temp = q.pop();
      cout << " " << temp->data << ":" << temp->meaning << " -> ";
      if (temp->left != NULL)
      {
        q.push(temp->left);
      }
      if (temp->right != NULL)
      {
        q.push(temp->right);
      }
    }
  }

  treenode *copy_rec(treenode *root)
  {
    treenode *temp;
    temp = NULL;
    if (root != NULL)
    {
      temp = new treenode;
      temp->data = root->data;
      temp->meaning = root->meaning;
      temp->left = copy_rec(root->left);
      temp->right = copy_rec(root->right);
    }
    return temp;
  }

  void mirror_rec(treenode *root)
  {
    treenode *temp;
    temp = NULL;
    if (root == NULL)
    {
      return;
    }
    else
    {
      temp = root->left;
      root->left = root->right;
      root->right = temp;
      mirror_rec(root->left);
      mirror_rec(root->right);
    }
  }
  treenode *min(treenode *node)
  {
    if (node->left == NULL)
    {
      return node;
    }
    else
    {
      min(node->left);
    }
    exit(0);
  }

  treenode *Dele(treenode *root, string key)
  {
    treenode *temp = NULL;
    if (root == NULL)
    {
      return NULL;
    }
    else if (key < root->data)
    {
      root->left = Dele(root->left, key);
    }
    else if (key > root->data)
    {
      root->right = Dele(root->right, key);
    }
    else if (key == root->data)
    {
      if (root->left == NULL && root->right == NULL)
      {
        delete root;
        root = NULL;
      }
      else if (root->right == NULL)
      {
        temp = root;
        root = root->left;
        delete temp;
      }
      else if (root->left == NULL)
      {
        temp = root;
        root = root->right;
        delete temp;
      }
      else
      {
        temp = min(root->right);
        root->data = temp->data;
        root->right = Dele(root->right, temp->data);
      }
    }
    return root;
  }
  void inorder(treenode *root)
  {
    if (root == NULL)
    {
      return;
    }
    else
    {
      inorder(root->left);
      cout << " " << root->data << ":" << root->meaning << " -> ";
      inorder(root->right);
    }
  }
};
int main()
{
  bstree b1;
  struct treenode *root1, *root2;
  int ch, choice;
  string key;
  do
  {
    cout << "---------------BST-----------------\n";
    cout << "1. Create binary search tree\n";
    cout << "2. Inorder search traversal\n";
    cout << "3. Display in level order\n";
    cout << "4. copy BST\n";
    cout << "5. Mirror BSt\n";
    cout << "6. Delete node from BST\n";
    cout << "-----------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      root1 = b1.create_bstree();
      break;
    case 2:
      b1.inorder(root1);
      break;
    case 3:
      b1.level_order(root1);
      break;
    case 4:
      root2 = b1.copy_rec(root1);
      b1.inorder(root2);
      break;
    case 5:
      b1.mirror_rec(root2);
      b1.inorder(root2);
      break;
    case 6:
      cout << "Enter the node to Delete: ";
      cin >> key;
      b1.Dele(root1, key);
      break;
    default:
      cout << "Invalid choice";
    }
    cout << "\nPress 1 to continue: ";
    cin >> ch;
  } while (ch == 1);
  return 0;
}