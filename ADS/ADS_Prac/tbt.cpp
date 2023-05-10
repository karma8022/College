#include<iostream>
using namespace std;

class node{
    int data;
    int lbit , rbit = 0;
    node* left;
    node* right;
    friend class tree;
    friend node*inorder(node*);
    friend node*inhelp(node*);
    public:
        node(){
            lbit = 1;
            rbit = 1;
        }
        

};

class tree{
    node* root;
    node* head;
    
    public:
        void create();
        void inorder();
        tree(){
            head = new node;
            head->data=-1;
            head->left=head;
            head->right=head;
            head->rbit=0;
        }
};

void tree::create(){
    root = new node;
    cout<<"Enter the value of the node"<<endl;
    cin>>root->data;
    head->left=root;
    head->lbit=0;
    root->left=head;
    root->right=head;

    char c;
    do{
        int flag = 0;
        node * temp = root;
        node * curr = new node;
        cout<<"Enter the new values"<<endl;
        cin>>curr->data;
        curr->left=NULL;
        curr->right=NULL;
        flag=0; 

        while(flag==0){
            cout<<"Enter L for left and R for right"<<endl;
            cin>>c;
            if(c=='L'||c=='l'){
                if(temp->lbit=1){
                    curr->right=temp;
                    curr->left=temp->left;
                    temp->left=curr;
                    temp->lbit=0;
                    flag =1 ;
                }
                else{
                temp = temp->left;
            }
            }
            if(c=='R'||c=='r'){
                if(temp->rbit==1){
                    curr->left=temp;
                    curr->right=temp->right;
                    temp->right=curr;
                    temp->rbit=0;
                    flag=1;
                }
                else{
                temp=temp->right;
                }
            }
            cout << "Enter Y to Accept more Data" << endl;
            cin >> c;
        }
    }while(c=='y'||c=='Y');
}

void tree::inorder(){
    node*temp =head;
    while(1){
        temp = inhelp(temp);
        if(temp==head){
            break;
        }
        cout<<temp->data<<endl;
    }
}

node* inhelp(node * temp){
    node * x = temp->right;
    if (temp->rbit == 0) {
    while (x->lbit == 0) {
      x = x->left;
    }
  }
  return x;
}

int main(){
    tree t;
    t.create();
    t.inorder();
}