#include <iostream>
using namespace std;

int main(){
    try{
        int a ;
    cout<<"Enter value of a ";
    cin>>a;
    if(a>5){
        throw a;
    }
    }
    catch (int a){
        cout<<"Number greater than 5";
    }
}