#include <iostream>
#include <string.h>
using namespace std ; 
class Employee{
    public:
        int ID;
        string Name;
        int Age;
        double Income;
        string City;
        char Vehicle;
        public:
            void display(int ID,string Name,int Age,double Income,string City,char Vehicle);
            int main(int ID,string Name,int Age,double Income,string City,char Vehicle);

};



void Employee :: display(int ID,string Name,int Age,double Income,string City,char Vehicle)
{
    cout<<"Employee ID is :"<<ID;
    cout<<"Employee Name is :"<<Name;
    cout<<"Employee ID is :"<<Age;
    cout<<"Employee ID is :"<<Income;
    cout<<"Employee ID is :"<<City;
    cout<<"Employee ID is :"<<Vehicle;

};
int c=0;
int Employee :: main(int ID,string Name,int Age,double Income,string City,char Vehicle){
    Employee emp;
    try
    {
        cout<<"Enter ID"<<endl;
        cin>>ID;
        cout<<"Enter Name"<<endl;
        cin>>Name;
        cout<<"Enter age"<<endl;
        cin>>Age;
        if(Age<18||Age>55){
            throw(Age);
        }
        else{
            c++;
        }
        cout<<"Enter Income"<<endl;
        cin>>Income;
        if(Income>50000||Income<100000){
            c++;
        }
        else{
            throw(Income);
        }
        cout<<"Enter City"<<endl;
        cin>>City;
        if(City=="Pune"||City=="Mumbai"||City=="Chennai"||City=="Bangalore"){
            c++; 
        }
        else{
            throw(City);
        }
    }

    catch(int a){
        cout<<"Employee age is not in a the valid range"<<endl;
    }
    catch(double d){
        cout<<"Enployee income is noot in the valid range"<<endl;
    }
    catch(string c){
        cout<<"Employee city is not valid ";
    }
    
    emp.display(ID,Name,Age,Income,City,Vehicle);


return 0;
};