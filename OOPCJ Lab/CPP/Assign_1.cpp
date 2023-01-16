#include <iostream>

using namespace std;

//Creating Class
class employee
{
	int   emp_number;
	string  emp_name;
	float emp_basic;
	float emp_da;
	float emp_it;
	float emp_net_sal;

	public:

		void get_emp_details();
		float find_net_salary(float basic, float da, float it);
		void show_emp_details();
        employee()
        {
            emp_number=0;
            emp_name="Null";
            emp_basic=0;
            emp_da=0;
            emp_it=0;
            emp_net_sal=0;
        };
};

//Getting Employee details 
void employee :: get_emp_details()
{
	cout<<"\nEnter employee number: ";
	cin>>emp_number;
	cout<<"\nEnter employee name: ";
	cin>>emp_name;
	cout<<"\nEnter employee basic: ";
	cin>>emp_basic;
	cout<<"\nEnter employee DA: ";
	cin>>emp_da;
	cout<<"\nEnter employee IT: ";
	cin>>emp_it;
}

//Finding net salary
float employee :: find_net_salary(float basic, float da, float it)
{
    return (basic+da)-it;
}
//Displaying employee details 
void employee :: show_emp_details()
{
	cout<<"\nEmployee Name      :  "<<emp_name;
	cout<<"\nEmployee number    :  "<<emp_number;
	cout<<"\nBasic salary       :  "<<emp_basic;
	cout<<"\nEmployee DA        :  "<<emp_da;
	cout<<"\nIncome Tax         :  "<<emp_it;
	cout<<"\nNet Salary         :  "<<find_net_salary(emp_basic, emp_da, emp_it);
}

//Main function 
int main()
{ 		
        employee emp;
        emp.get_emp_details();
        emp.show_emp_details();

    
    return 0;
}
