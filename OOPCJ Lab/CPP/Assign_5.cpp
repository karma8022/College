#include <iostream>
#include <fstream>
using namespace std;
 int main()
 {
    char name[30];
    float cost;
    ofstream outf("Product.txt");
    cout<<"Enter Product Name:";
    cin>>name;
    outf<<name<<"\n";
    cout<<"Enter product cost:";
    cin>>cost;
    outf<<cost<<"\n";
    outf.close();
    ifstream inf("{Product.txt");
    inf >> name ;
    inf >> cost ;
    cout<<"\n";
    cout<<"Product name:"<<name<<"\n";
    cout<<"Product cost:"<<cost<<"\n";
    inf.close();
    return 0;
 }

