#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        insertintobst(root,data);
        cin >> data;
    }
}

int main(){

    return 0;

}