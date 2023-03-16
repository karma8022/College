#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;

class N{
    public:
        int k;
    N *l , *r;
    bool leftTH , rightTH;
};

class ThreadBinaryTreee{
    private:
    N *root;
    public:
    ThreadBinaryTreee(){
        root = new N();
        root->r = root->l = root;
        root->leftTH = true;
        root->k = MAX_VALUE;
    }

    void makeEmpty(){
        root = new N();
        root->r = root->l = root;
        root->leftTH = true;
        root->k = MAX_VALUE;
    }

    void insert(int key){
        N *p = root;
        for(;;){
            if (p->k <key){
                if (p->rightTH){

                }
            }
        }
    }

};

int main(){
    ThreadBinaryTreee tbt;
    tbt.makeEmpty();
    return 0;
}