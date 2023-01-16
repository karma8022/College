#include <iostream>
#include <fstream>
using namespace std;
class store{
    int code;
    float cost;

public:
    void readdata();
    void displaydata();

};

void store::readdata(){
    cout<<"Enter book code"<<endl;
    cin>>code;
    cout<<"Enter cost"<<endl;
    cin>>cost;
}

void store::displaydata(){
    cout<<"\n"<<"\t"<<code<<"\t"<<cost<<endl;
}

int main(){
    store product[3];
    fstream file ;
    file.open("Book.txt",ios::in|ios::out);
    cout<<"Enter details of 3 books"<<endl;
    for(int i=0;i<3;i++){
        product[i].readdata();
        file.write((char*) &product[i],
        sizeof(product[i]));
    }

    file.seekg(0);
    cout<<"\n Book details";
    for(int i=0;i<3;i++){
        file.read((char*) &product[i],sizeof(product[i]));
        product[i].displaydata();
    }
    file.close();
    return 0;
}
